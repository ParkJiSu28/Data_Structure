﻿
#Data_Structure



## 대학생의 자료구조

 
### 1.파일 입출력

구조체를 활용한 파일 입출력.
구조체 변수 지정후 파일 포인터를 사용해 파일을 읽고 저장.

```

while (fscanf(fp, "%s %c %s %s %f %d %d", File[index].name, &File[index].gender, File[index].residence, File[index].subject, &File[index].grade, &File[index].height, &File[index].weight) != EOF) {
			index++;


```
    
    
EOF를 만날 때 까지 while문 반복 인덱스 증가 구조체변수 파일저장.


    
    


###2.list 연산
    
  list를 활용한 대표적인 연산을 구현한다.
   
  연산: Search,Insert ,Delete,Store  
    
  파일을 읽어 이에 해당하는 명령을 수행한다 .
  데이터를 읽어 처음부터 순서에 맞게 삽입하는것에 대해 유의해서 데이터를 삽입한다.
   
    
  나중에 따로 정렬 함수를 사용하지 않는다. LOAD단계에서 Insert 함수를 사용해서 순서에 맞게 삽입하는 점을 유의한다.
    
    
  ```
    
    ex)
    CREATE
    
    
    LOAD  임의의 파일이름.
    
    INSERT  XXX, XX,XXX,X,X,X,X
    
    SEARCH
    
    DLELTE XXXX
    
    PRINT 
    
    
    ETC...
    
   ``` 
    
    
    
  목표 :List를 활용한 대표적인 연산과 구조체를 활용하여 파일의 정보를 담는 연습을 한다.
    

    
    
    
  ###3. Linked-list
    
    Linked-list에 대한 구현과 위와 똑같은 연산을 진행해본다
    포인터를 활용한 자료구조로 포인터를 이해하고 사용해본다,
    똑같은 데이터파일을 읽어서 위와 같은 연산을 진행해본다.
      
    
    Linked-list 에 대한 기본적인 정의는 이와 같이 진행하였다.
    
  ```
    
    typedef struct _node node;
struct _node {
	Student item;
	node *link;
};

node *head = NULL;
    
    
  ```
    
    
    
    
  목표 : Linked-list를 구현한다.  2번과 같이 명령어들을 수행한다,
    
    
    
    
        