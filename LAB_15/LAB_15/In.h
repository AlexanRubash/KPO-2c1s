#pragma once

#define IN_MAX_LEN_TEXT 1024*1024
#define IN_CODE_ENDL '\n'

#define Test_Hi
//#define Test_Me


		//0     //1     //2     //3     //4     //5     //6     //7     //8     //9     //A     //B     //C     //D     //E     //F		//Hello World!!!
																																		//ПрXивеXт Мир!Y!
#ifdef Test_Hi

#define IN_CODE_TABLE {\
/*0*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  '|',  IN::F,  IN::F,  IN::I,  IN::F,  IN::F,\
/*1*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*2*/ IN::T,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*3*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*4*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*5*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::T,  IN::I,    '!',  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*6*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::T,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::T,  IN::F,  IN::F,  IN::T,\
/*7*/ IN::F,  IN::F,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
                                                                                                                                    \
/*8*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*9*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*А*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*В*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*С*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::T,  IN::F,  IN::F,  IN::T,\
/*D*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*E*/ IN::F,  IN::F,  IN::T,  IN::F,  IN::F,  IN::T,  IN::F,  IN::F,  IN::T,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*F*/ IN::T,  IN::F,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F \
					  }

#endif // Test_Hi



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#ifdef Test_Me

#define IN_CODE_TABLE {\
/*0*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*1*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*2*/ IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*3*/ IN::T,  IN::F,  IN::T,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*4*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,\
/*5*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::I,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*6*/ IN::F,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::T,  IN::F,  IN::F,  IN::T,  IN::F,  IN::T,  IN::T,  IN::F,  IN::T,  IN::T,\
/*7*/ IN::F,  IN::F,  IN::F,  IN::T,  IN::F,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
                                                                                                                                    \
/*8*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*9*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*A*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*B*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*C*/	'-',  IN::F,  IN::F,  IN::F,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*D*/ IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,\
/*E*/ IN::T,  IN::F,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::T,  IN::T,  IN::T,  IN::T,  IN::T,  IN::F,  IN::T,  IN::T,  IN::F,\
/*F*/ IN::F,  IN::T,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::F,  IN::T,\
					  }

#endif // Test_Me


		//0     //1     //2     //3     //4     //5     //6     //7     //8     //9     //A     //B     //C     //D     //E     //F	    //Kozliakouski Danila
																																		//Козляковский Данила
																																		//2003 Ананас XanaXcdcd
namespace In
{
	struct IN
	{
		enum { T = 1024, F = 2048, I = 4096 };
		int size;
		int lines;
		int ignor;
		unsigned char* text;
		int code[256];
	};
	IN getin(wchar_t* infile);
}
