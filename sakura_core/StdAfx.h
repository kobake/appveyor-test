// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���A
//				�܂��͎Q�Ɖ񐔂������A�����܂�ύX����Ȃ�
//				�v���W�F�N�g��p�̃C���N���[�h �t�@�C�����L�q���܂��B
//

#if !defined(AFX_STDAFX_H__11490042_E569_11D3_BCE2_444553540001__INCLUDED_)
#define AFX_STDAFX_H__11490042_E569_11D3_BCE2_444553540001__INCLUDED_

#if defined(_MSC_VER) && _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// ���̈ʒu�Ƀw�b�_�[��}�����Ă�������
// #define WIN32_LEAN_AND_MEAN		// Windows �w�b�_�[����w�ǎg�p����Ȃ��X�^�b�t�����O���܂�
#ifndef STRICT
#define STRICT 1
#endif

#if defined(_MSC_VER) && _MSC_VER >= 1400

//#pragma warning(disable: 4786)
#pragma warning(disable: 4345)	//warning C4345: ����ύX : �`�� () �̏������q�ō\�z����� POD �^�̃I�u�W�F�N�g�͊��菉��������܂��B
#pragma warning(disable: 4996)	//warning C4996: 'xxxx': This function or variable may be unsafe. Consider using wcscpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
#pragma warning(disable: 4355)	//warning C4355: 'this' : �x�[�X �����o���������X�g�Ŏg�p����܂����B

#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

#ifdef __MINGW32__
#include <_mingw.h>
#ifdef MINGW_HAS_SECURE_API
#undef MINGW_HAS_SECURE_API
#endif  // MINGW_HAS_SECURE_API
#endif  // __MINGW32__

//���p�xAPI��
// #include <CommDlg.h> // WIN32_LEAN_AND_MEAN�ł͕K�v�BOpenFileDialg�n

#include <windows.h>
#include <CommCtrl.h> // �R�����R���g���[��
#include <stdlib.h>  // _MAX_PATH
#include <wchar.h>

#ifndef SAKURA_PCH_MODE_MIN
// 2010.04.19 �d�����Ȃ̂Œǉ�
#include <HtmlHelp.h>
#include <ObjIdl.h>
#include <ShlObj.h>
#include <ShellAPI.h>
#include <string.h>
#include <stdio.h>
#include <io.h>
#include <time.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#endif // ifndef SAKURA_PCH_MODE_MIN

#if defined(__MINGW32__) && defined(_countof)
#define BUILD_OPT_NEW_HEADERS
#endif

//���̑�
#define malloc_char (char*)malloc
#define GlobalLockChar  (char*)::GlobalLock
#define GlobalLockUChar (unsigned char*)::GlobalLock
#define GlobalLockWChar (wchar_t*)::GlobalLock
#define GlobalLockBYTE  (BYTE*)::GlobalLock


// 2010.04.19 Moca include�̑�K�͐���
#ifndef SAKURA_PCH_MODE_MIN
#define SAKURA_PCH_MODE_DLLSHARE 1
#endif

#ifdef SAKURA_PCH_MODE_MAX
#include "env/CShareData.h"
#include "_main/CNormalProcess.h"
#include "_main/CAppMode.h"
#include "window/CEditWnd.h"
#include "CEditApp.h"
#include "doc/CDocReader.h"
#include "docplus/CModifyManager.h"
#include "docplus/CDiffManager.h"
#include "docplus/CBookmarkManager.h"
#include "CReadManager.h"
#include "CWriteManager.h"
#include "CSearchAgent.h"
//###########����
#include "uiparts/CGraphics.h"
#endif // SAKURA_PCH_MODE_MAX

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_STDAFX_H__11490042_E569_11D3_BCE2_444553540001__INCLUDED_)



