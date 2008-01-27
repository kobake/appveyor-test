/*
	2007.09.30 kobake �쐬

	++ �T�v ++

	enum �� define ��2��ނ̒萔��`�w�b�_�𐶐����邽�߂̃��m

	enum�萔�̓\�[�X�R�[�h����Q�Ƃ��A(�f�o�b�O�����₷���Ȃ�)
	define�萔�̓��\�[�X����Q�Ƃ���  (���\�[�X���ł�enum�萔�𗘗p�ł��Ȃ�)


	++ �ˑ� ++

	Visual Studio �� cl.exe �Ɉˑ��B
	cl.exe �̃v���v���Z�b�T�@�\�𗘗p���Ă��܂��B


	++ �g�p���@ ++

	usage() ���Q��
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
using namespace std;

enum EMode{
	MODE_INVALID,

	MODE_ENUM,
	MODE_DEFINE,
};

int usage()
{
	printf("HeaderMake -in=<���̓t�@�C��> -out=<�o�̓t�@�C��> -mode=<���[�h> [-enum=<enum��>]\n");
	printf("���[�h\n");
	printf("  define  �c #define �ɂ��萔��`�w�b�_�𐶐�n");
	printf("  enum    �c enum �ɂ��萔��`�w�b�_�𐶐��B<enum��>���w�肷��΂��ꂪ�񋓌^�̖��O�ɂȂ�\n");
	return 1;
}

inline bool is_token(char c)
{
	return __iscsym(c) || c=='-';
}

//! ��납�猟�����Ac1 �� c2 �A��Ɍ��������ق��̃A�h���X��Ԃ�
const char* strrchr2(const char* str, char c1, char c2)
{
	const char* p=strchr(str,'\0');
	//��while���s����ƁAc1,c2��'\0'�̂Ƃ���NULL��Ԃ��Ă��܂��̂ŁAdo�`while�Ƃ����B
	do{
		if(*p==c1 || *p==c2)return p;
	}while(--p>=str);
	return NULL;
}

const char* GetFileTitlePointer(const char* fpath)
{
	const char* p=strrchr2(fpath,'\\','/');
	if(p){
		return p+1;
	}
	else{
		return fpath;
	}
}

int main(int argc,char* argv[])
{
	//��������
	const char* in_file  =NULL;
	const char* out_file =NULL;
	const char* mode_name=NULL;
	const char* enum_name="";
	for(int i=1;i<argc;i++){
		char* p=argv[i];
		if(*p=='/')*p='-';
		if(strncmp(p,"-in",3)==0){
			p+=3;
			if(*p!='\0'){ if(*p=='=')p++; in_file=p; }
			else in_file=argv[++i];
		}
		else if(strncmp(p,"-out",4)==0){
			p+=4;
			if(*p!='\0'){ if(*p=='=')p++; out_file=p; }
			else out_file=argv[++i];
		}
		else if(strncmp(p,"-mode",5)==0){
			p+=5;
			if(*p!='\0'){ if(*p=='=')p++; mode_name=p; }
			else mode_name=argv[++i];
		}
		else if(strncmp(p,"-enum",5)==0){
			p+=5;
			if(*p!='\0'){ if(*p=='=')p++; enum_name=p; }
			else enum_name=argv[++i];
		}
		else{
			printf("Error: �s���Ȉ���[%s]\n",p);
			return 1;
		}
	}
	if(!in_file)  { printf("Error: ���̓t�@�C�����w�肵�Ă�������\n\n"); return usage(); }
	if(!out_file) { printf("Error: �o�̓t�@�C�����w�肵�Ă�������\n\n"); return usage(); }
	if(!mode_name){ printf("Error: ���[�h���w�肵�Ă�������\n\n");       return usage(); }


	//���[�h����
	EMode mode=MODE_INVALID;
	if(_stricmp(mode_name,"DEFINE")==0)mode=MODE_DEFINE;
	else if(_stricmp(mode_name,"ENUM")==0)mode=MODE_ENUM;
	else{
		printf("Error: �s���ȃ��[�h[%s]�ł�\n",mode_name);
	}


	//�t�@�C���X�V������r (�Ȃ񂩁AVS�̃J�X�^���r���h�����܂������Ȃ��̂ŁA�����Ŕ���(��) )
	struct _stat in_stat;
	struct _stat out_stat;
	if(-1==_stat(in_file, &in_stat ))goto next;
	if(-1==_stat(out_file,&out_stat))goto next;
	//���̓t�@�C�����V������Ώ����𑱍s����
	if(in_stat.st_mtime>out_stat.st_mtime)goto next;
	else{ printf("�o�̓t�@�C���͍ŐV�ł�\n"); return 0; }


next:
	//�t�@�C���I�[�v��
	char in_file2[_MAX_PATH];
	sprintf_s(in_file2,_countof(in_file2),"cl.exe /EP %s",in_file);
	FILE* in=_popen(in_file2,"rt");               if(!in ){ printf("Error: ���̓t�@�C�����J���܂���\n"); return 1; } //���v���v���Z�X�ς݃X�g���[��
	FILE* out=NULL; fopen_s(&out,out_file,"wt");  if(!out){ printf("Error: �o�̓t�@�C�����J���܂���\n"); return 1; }


	//����
	char line[1024];
	fprintf(out,"#pragma once\n\n");
	fprintf(out,
		"//���̃t�@�C���� HeaderMake �ɂ�� %s ���琶�����ꂽ�t�@�C���ł��B\n"
		"//���ڕҏW���Ȃ��ł��������B\n\n",
		GetFileTitlePointer(in_file)
	);
	if(mode==MODE_ENUM)fprintf(out,"enum %s{\n",enum_name); //enum�J�n
	while(NULL!=fgets(line,_countof(line),in))
	{
		//���s����
		{
			char* p=strrchr(line,'\n');
			if(p && *(p+1)=='\0')*p='\0';
		}

		//�g�[�N�����o�J�n
		const char* p=line;
		const char* q;

		//ID������ -> id
		char id[256];
		while(*p && !is_token(*p))p++;
		q=p;
		while(*q && is_token(*q))q++;
		strncpy_s(id,_countof(id),p,q-p);
		id[q-p]='\0';
		p=q;

		//�l -> value
		char value[256];
		while(*p && !is_token(*p))p++;
		q=p;
		while(*q && is_token(*q))q++;
		strncpy_s(value,_countof(value),p,q-p);
		value[q-p]='\0';
		p=q;

		//�o��
		if(*id && *value){
			if(mode==MODE_ENUM){
				fprintf(out,"\t%s = %s,\n",id,value);
			}
			else if(mode==MODE_DEFINE){
				fprintf(out,"#define %s %s\n",id,value);
			}
		}
	}
	if(mode==MODE_ENUM)fprintf(out,"};\n"); //enum�I��


	//��n��
	fclose(out);
	fclose(in);
	return 0;
}