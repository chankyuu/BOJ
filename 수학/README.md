# 수학
## 소수
* 소수의 정의 :
> 소수 = 1과 자기 자신으로만 나누어지는 수 = 약수가 2개인 수 = 2부터 N-1까지의 수로 나누어지지 않는 수
> > 소수 판정법 : 합성수 N에서 1을 제외한 가장 작은 약수는 루트(N) 이하이다.
> > 에라토스테네스의 체 등 1978번 소수찾기 참고

* 합성수 = 1과 자기 자신을 제외한 다른 약수를 가지고 있는 수

## 최대공약수
* 유클리드 호제법 사용
> gcd(20, 12) = gcd(12, 8) = gcd(8, 4) = gcd(4, 0) 즉, gcd(a, b) = gcd(b, a % b)

## 최소공배수
* A * B = gcd(A, B) * lcm(A, B) 성질 이용
> lcm(A, B) = A * lcm(A, B) / B


## 연립합동방정식
* 6064번 카잉달력 문제 참고


## 이항계수
* DP 이용
> D[i][j] = iCj 임을 생각하여 DP 이용.
