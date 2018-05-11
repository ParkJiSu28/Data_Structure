
#Data_Structure



## 대학생의 자료구조

 
### 1.파일 입출력

구조체를 활용한 파일 입출력.
구조체 변수 지정후 파일 포인터를 사용해 파일을 읽고 저장.

``

while (fscanf(fp, "%s %c %s %s %f %d %d", File[index].name, &File[index].gender, File[index].residence, File[index].subject, &File[index].grade, &File[index].height, &File[index].weight) != EOF) {
			index++;


``
    
    
EOF를 만날 때 까지 while문 반복 인덱스 증가 구조체변수 파일저장.




###2.list 연산
    
  list를 활용한 대표적인 연산을 구현한다.
   
  연산: Search,Insert ,Delete,Store  
    
  파일을 읽어 이에 해당하는 명령을 수행한다 .
  
    
    
  ``
    ex)
    CREATE
    
    
    LOAD  임의의 파일이름.
    
    INSERT  XXX, XX,XXX,X,X,X,X
    
    SEARCH
    
    DLELTE XXXX
    
    PRINT 
    
    
    ETC...
    
    ``
    
    목표 :List를 활용한 대표적인 연산과 구조체를 활용하여 파일의 정보를 담는 연습을 한다.
    
    