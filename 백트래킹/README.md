# 백트래킹
* 백트래킹의 정의 :
> 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘

* next_permutation
> 순열과 조합을 해결할 수 있는 깔끔한 방법
> 
> 현재의 수열을 사전 순으로 생각했을때의 다음 수열로 만들고 true를 반환
> 
>> ex) 순열
>> 
>> int a[3] = {1, 2, 3};
>> 
>> do {
>> 
>>  for(int i = 0; i < 3; i++)
>>  
>>    cout << a[i];
>>    
>>  cout << ", ";
>>  
>>  } while(next_permutation(a, a+3));
>>  
>>  이 경우 값은 123, 132, 213, 231, 312, 321 과 같이 출력

>> ex) 조합(1234에서 수 2개를 순서없이 뽑는 모든 경우를 출력)
>> 
>> 0과 1을 이용하면 된다!
>> 
>> int a[4] = {0, 0, 1, 1};
>>
>> do {
>>
>>  for(int i = 0; i < 4; i++)
>>
>>    if(a[i] == 0)
>>
>>      cout << i+1;
>>
>>  cout << ", ";
>>
>>  } while(next_permutation(a, a+4));
>>
>>  이 경우 값은 12, 13, 14, 23, 24, 34 과 같이 출력
>>
>> 5개에서 3개를 뽑는 문제라면 a[5] = {0, 0, 0, 1, 1}로 두면 된다.

* 중복조합(aHb)
> aHb = b개의 원소 중에 중복을 허용해 a개를 뽑는 경우의 수
> aHb = a+b-1 C b-1
> a+b-1 C b-1 = a+b-1개의 원소 중에 중복을 허용하지 않고 b-1개를 뽑는 경우의 수
