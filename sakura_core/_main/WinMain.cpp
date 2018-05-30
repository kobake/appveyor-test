/*!	@file
	@brief Entry Point

	@author Norio Nakatani
	@date	1998/03/13 �쐬
	@date	2001/06/26 genta ���[�h�P�ʂ�Grep�̂��߂̃R�}���h���C�������ǉ�
	@date	2002/01/08 aroka �����̗���𐮗��A���g�p�R�[�h���폜
	@date	2002/01/18 aroka ����聕�����[�X
	@date	2009/01/07 ryoji WinMain��OleInitialize/OleUninitialize��ǉ�
*/
/*
	Copyright (C) 1998-2001, Norio Nakatani
	Copyright (C) 2001, genta
	Copyright (C) 2002, aroka
	Copyright (C) 2007, kobake
	Copyright (C) 2009, ryoji

	This source code is designed for sakura editor.
	Please contact the copyright holder to use this code for other purpose.
*/

#include "StdAfx.h"
#include <Ole2.h>


int WINAPI WinMain(
	HINSTANCE	hInstance,		//!< handle to current instance
	HINSTANCE	hPrevInstance,	//!< handle to previous instance
	LPSTR		lpCmdLineA,		//!< pointer to command line
	int			nCmdShow		//!< show state of window
)
{
	::MessageBoxW(NULL, L"Hello AppVeyor", L"Dialog", MB_OK);
	return 0;
}


