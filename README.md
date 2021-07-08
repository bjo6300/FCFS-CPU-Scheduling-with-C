# CPU Scheduling Algorithm FCFS

** FCFS(First Come First Served) 설계 및 구현 (C언어)

* FIFO (First In First Out)와 같은 의미 
* 가장 오래 기다린 프로세스가 다음으로 실행
* Non-preemtive 모드로 긴 프로세스에 유리
* 입출력 중심의 프로세스보다 처리기 중심 프로세스를 우대하는 경향

------------

# Input Data
~~~
 Type ProcessID Priority Computing_Time
  0    1         25       80
  0    2         15       40
  0    3         8        30
  1    0         0        0
  0    4         12       10
  0    5         22       30
  0    6         28       50
  1    0         0        0
  0    7         5        20
  0    8         3        40
  0    9         13       60
  1    0         0        0
  0    10        24       45
  -1   
~~~

* Type 
 
  *  0 : 프로세스 생성
 
  *  1 : 한 프로세스의 시간할당량이 다되어 스케줄 (default : 20)
  
  * -1 : 입력 완료
 
* ProcessID
 
  * 프로세스 아이디 (중복X)

* Priority
  
  * 우선순위
  
* Computing Time

  * 각 프로세스가 필요한 compute time
  
------
# Output Process Data

~~~
ProcessID Priority Computing_Time Turn_around_time
    1        25         80            80
    2        15         40            120
    3         8         30            150
    4        12         10            140
    5        22         30            170
    6        28         50            220
    7         5         20            220
    8         3         40            260
    9        13         60            320
   10        24         45            345
   
 Normalized turn around time : 6.356667
~~~
* ProcessID
 
  * 프로세스 아이디 (중복X)

* Priority
  
  * 우선순위

* Computing Time

  * 각 프로세스가 필요한 compute time

* Turn around time

  * 종료시간 - 도착시간 

* Normalized turn around time

  * (종료시간 - 도착시간) / computing time



