# miniC-Compiler-Project



## 형식언어 및 컴파일러 Project (Control Flow Graph & Data Flow Analysis)

mini C++ Compiler # 2

제작자 : 김민성
    
[프로젝트 설명]

AST의 경우엔,  PA1.pdf에 정의되어있는 mini C++ 문법을 바탕으로 구성되어 있습니다.

입력
- miniC++ 문법을 바탕으로 작성된 cpp Source COde

출력
- AST_Restore_code.cpp : 생성된 AST를 바탕으로, 재귀적으로, 복원된 코드
- AST_Symbol_Table.txt : 해당 변수들에 대한 심볼테이블
- CFG.out : AST에 대한 Control Flow Graph


miniC++ 문법을 바탕으로 만들었으며, make 를 통해서, 빌드후 위의

./miniC++ test.cpp 명령을 터미널에서 실행하면 해당 컴파일러가 동작하면서,

AST_Symbol_Table.txt 파일과 AST_Restore_code.cpp CFG.out 파일이 생성되어집니다.



