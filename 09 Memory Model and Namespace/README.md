# 메모리 모델과 이름 공간
- 분할 컴파일
- 위치 지정 new
- 기억 존속 시간, 사용 범위, 링크
- 이름 공간

C++ 에서는 메모리에 데이터를 여러 가지 방법으로 저장할 수 있다. <br>
일반적으로 덩치 큰 프로그램은 데이터를 공유하는 여러 개의 소스 코드 파일들로 구성된다.

## 분할 컴파일
파일들을 개별적으로 분할하여 컴파일한 후에, 그것들을 하나의 최종 실행 프로그램으로 링크할 수 있다. <br>
만일 어떤 하나의 파일을 수정했다면, 그 파일 하나만을 다시 컴파일해서, 이미 컴파일되어 있는 다른 파일들과 `링크`하면 된다.

### 헤더 파일
- 함수 원형
- `#define`이나 `const`를 사용하여 정의하는 기호 상수
- 구조체 선언
- 클래스 선언
- 템플릿 선언
- 인라인 함수

`구조체`선언은 변수를 만들지 않기 때문에 헤더 파일에 넣어도 된다. <br>
`템플릿`선언도 컴파일되는 코드가 아니다. 소스 코드에서 발견된 함수 호출에 대응하는 함수 정의를 생성하는 방법을 컴파일러에게 지시한다. <br>

헤더 파일을 포함시킬 때 `<>`로 묶여있다면 컴파일러는 표준 헤더 파일들이 들어 있는 호스트 시스템의 파일 시스템 영역에서 찾고,
`""`로 묶여 있으면, 현재 작업 디렉토리나 소스 코드 디렉토리에서 찾는다. 사용자가 만든 헤더 파일을 포함시킬 때에는 각진 괄호 대신에 큰따옴표를 사용해야 한다.

### 헤더 파일의 관리
헤더 파일을 어떤 파일에 포함시킬 때에는 `단 한 번만 포함`시켜야 한다. 헤더 파일을 여러 번 포함시키는 실수를 저지르기가 쉽다.
C와 C++에서 헤더 파일을 여러 번 포함시키는 실수를 피하기 위해 사용하는 표준 기법이 있다.
`전처리기 지시자`인 `#ifndef(if not defined)`를 사용하는 것이다.

```cpp
#ifndef COORDIN_H_
...
#endif
```

`COORDIN_H_`라는 이름의 전처리기 지시자 `#define`에 의해 정의되어 있지 않은 경우에만, `#ifndef`와 `#endif` 사이에 있는 구문들을 처리하라는 뜻이다.

```cpp
#ifndef COORDIN_H_
#define COORDIN_H_
// 포함시킬 include 파일의 내용을 여기에 추가한다.
#endif
```

다른 곳에서 좀처럼 사용할 것 같지 않은 이름으로 만들기 위해, `밑줄`문자를 사용하는 관습이 있는 것 같다. <br>
해당 기법은 컴파일러가 한 파일을 2번 포함시키는 것을 막지는 못한다. 그 대신, 처음으로 포함시킨 것을 제외한 나머지는 컴파일러가 무시하게 만든다.
이렇게 하지 않으면 하나의 파일에 2번 정의된 동일한 구조를 얻게 될 수도 있게 되며, 이것은 컴파일 에러를 유발시킬 것이다.

## 기억 존속 시간, 사용 범위, 링크
여러 개의 파일로 이루어진 하나의 프로그램을 만드는 것을 배웠다.
C++은 4가지 유형으로 데이터를 저장한다.

### 자동 기억 존속 시간(automatic storage duration)
`함수 매개변수`를 포함하여, 함수 정의 안에 선언된 변수는 자동 기억 존속 시간을 가진다. 프로그램 실행이 그들을 정의하고 있는 함수나 블록 안으로 들어갈 때 `생성`된다.
그들에게 대입된 메모리는 프로그램 실행이 해당 함수나 블록을 떠날 때 `해제`된다. <br>
C++ 은 2종류의 `자동 변수`를 가진다.

### 정적 기억 존속 시간(static storage duration)
함수 정의의 바깥에서 정의된 변수 또는 키워드 `static`를 사용하여 정의된 변수는 정적 기억 존속 시간을 가진다.
프로그램이 실행되는 전체 시간 동안 존속한다. <br>
C++ 은 3종류의 `정적 변수`를 가진다.

### 쓰레드 존속 시간(Thread storage duration(C++11))
`여러 작업을 동시에 처리할 수 있는 CPU`를 의미한다. 멀티코어 프로세서를 사용하여 연산 작업을 쓰레드(thread)단위로 쪼개서 처리한다.

### 동적 기억 존속 시간(dynamic storage duration)
`new`연산자를 사용하여 대입된 메모리는 `delete`연산자로 해제되거나 프로그램이 종료할 때까지 둘 중 어느 것이 먼저 일어날 때까지 존속하게 된다.
이 메모리는 동적 기억 존속 시간을 가지며 때로는 이 메모리를 `자유 공간`이라고도 한다.

#### 사용 범위와 링크
`사용 범위(scope)`는 어떤 이름이 하나의 파일(번역 단위) 안에서 얼마나 널리 알려지는가를 나타낸다. <br>
ex) 함수 안에서 정의된 변수는 그 함수 안에서만 사용할 수 있고, 다른 함수에서는 사용할 수 없게 된다. <br>
`링크(linkage)`는 서로 다른 번역 단위들이 이름을 공유하는 것을 말한다. <br>
`외부 링크(external linkage)`를 가진 이름은 여러 파일들이 공유할 수 있다. <br>
`내부 링크(internal linkage)`를 가진 이름은 한 파일 안에 있는 함수들만 공유할 수 있다. <br>
`자동 변수`는 공유되지 않기 때문에 자동 변수의 이름은 `링크`를 갖지 않는다.

##### 지역 사용 범위(local scope)
`블록 사용 범위`를 가지는 변수는 그 변수를 정의한 블록 안에서만 알려진다. `블록`은 중괄호로 묶인 연속된 구문들이다. <br>

##### 전역 사용 범위(global scope)
그것이 정의된 지점부터 그 아래로 파일 전체에 걸쳐 알려진다.

`자동 변수`는 지역 사용 범위를 가진다. <br>
`정적 변수`는 어떻게 정의되는가에 따라 지역 사용 범위와 전역 사용 범위 중에 하나를 가지게 된다. <br>

##### 함수 원형 사용 범위(function prototype scope)
매개변수 리스트를 둘러싸고 있는 괄호 안에만 알려진다. 그렇기 때문에 이름이 무엇이든 간에 상관이 없고 이름이 없다고 해서 문제가 되지 않는다.

##### 클래스 사용 범위(class scope)
클래스 안에 선언된 멤버가 가지는 범위다.

##### 이름 공간 사용 범위(namespace scope)
어떤 이름 공간 안에 선언된 변수는 이름 공간 사용 범위를 가진다.

## 자동 변수
함수 매개변수와 함수 안에서 선언된 변수는 기본적으로 자동 기억 존속 시간을 가진다.
이들은 또한 지역 사용 범위를 가지며 링크는 없다. 프로그램 실행이 그 블록에 들어갈 때 대입되지만, 이들 변수의 사용 범위는 변수가 선언된 시점부터 시작된다.
```cpp
int main()
{
	int teledeli = 5;
	{
		int websight = 2;
		cout << websight << endl;
	}
	cout << teledeli << endl;
}
```

만약에 `teledeli`가 `websight`였다면? 안쪽 블록에 신규 정의가 이전 정의의 앞을 가린다고 한다.
신규 정의가 사용 범위 안으로 들어오고, 이전 정의는 사용 범위 밖으로 잠시 물러나며, 프로그램이 안쪽 블록을 벗어날 때 원래의 정의가 다시 사용 범위 안으로 복귀한다.

### C++11에서의 auto 변화
명시적으로 벼수는 자동 저장소로 인식되어 있다.
```cpp
int froob(int n)
{
	auto float ford;
}
```

`auto`키워드는 자동 변수에만 사용할 수 있기 때문에, 프로그래머들은 auto 키워드에 대해 별로 신경을 쓰지 않는다.

### 자동 변수의 초기화
선언에 도달된 시점에서 값을 알 수 있다면, 어떠한 표현식을 사용하더라도 초기화할 수 있다.

### 자동 변수와 스택
프로그램은 실행 동안에 자동 변수를 스스로 관리해야 한다.
일반적인 방법은 메모리의 일부를 예약해 두고, 변수들의 생성과 소멸을 `스택`으로 관리하는 것이다.
새로 생성되는 데이터는 먼저 생성된 데이터의 위에 쌓이고(같은 위치가 아닌 인접한 위치), 프로그램이 데이터의 사용을 마치면 그 데이터는 스택에서 제거된다.
`스택`의 크기는 C++마다 다르지만 일반적으로 사용자가 스택의 크기를 선택할 수 있다.

프로그램은 2개의 포인터를 이용하여 스택을 관리한다. <br>
1개의 포인터는 스택으로 예약한 메모리의 시작 위치인 스택의 바닥을 지시한다. <br>
1개의 포인터는 다음 번 데이터의 저장을 위해 비어 있는 메모리 위치인 스택의 꼭대기를 지시한다.

함수가 호출되면 그 함수의 자동 변수들이 스택에 추가된다. 꼭대기를 지시하는 포인터는 새로 추가된 변수들을 지나서 새롭게 사용할 수 있는 빈 위치를 지시한다.
함수가 종료된다면, 새로운 변수가 사용했던 기억 장소는 해제되고, 꼭대기를 지시하는 포인터는 그 함수가 호출되기 이전의 위치를 다시 지시한다.

`스택(LIFO, List in First out, 후입선출)` 가장 나중에 들어온 변수가 가장 먼저 나간다는 뜻.
후입선출 설계는 매개변수의 전달 과정을 간단하게 만든다. 함수 호출은 매개변수의 값들을 스택의 꼭대기에 넣고, 꼭대기를 지시하는 포인터를 다시 설정한다.

### 레지스터 변수
본래 C는 `register`키워드를 제공함으로서 컴파일러가 CPU 레지스터를 사용해서 자동 변수를 저장할 것을 제안한다.
```c
register int count_fast;
```

아이디어는 변수에 더욱 빨리 접근하는 것을 허용하기 위함이었다. C++11 이전의 C++은 하드웨어와 컴파일러가 매우 세밀히 개발된 경우를 제외하고는 `register`키워드가 자주 사용되는 변수라는 의미로
컴파일러가 해당 변수에 특별한 조치를 취한다는 의미로 일반화하여 위의 목적을 추구했었다.

C++11에서는 이러한 것들이 사라졌지만, `register`키워드를 어떤 한 변수가 자동적임을 명시하도록 남겨두었다.
또 이 키워드를 사용하는 기존의 코드가 인식이 불가능해지는 것을 방지하기 위함이기도 하다. (남겨둔 이유)

### 정적 변수
프로그램이 실행되는 전체 시간동안 존속한다.
정적 변수의 개수는 프로그램이 실행되는 동안에 변하지 않기 때문에, 모든 정적 변수를 수용할 수 있을 만큼 넉넉하게 크기가 정해진 메모리 블록을 대입한다.
이 블록에 저장되는 정적 변수들은 프로그램이 실행되는 동안에 계속 존재하게 된다.
정적 변수를 `명시적`으로 초기화하지 않으면? 컴파일러는 그것들을 전부 `0`으로 초기화한다.
정적 배열과 구조체는 그것의 원소나 멤버가 기본적으로 `0`으로 설정된다.

```cpp
int global = 1000;        // 정적 기억 존속 시간, 외부 링크
static int one_file = 50; // 정적 기억 존속 시간, 내부 링크

int main()
{
}

void funct1(int n)
{
	static int count = 0; // 정적 기억 존속 시간, 링크 없음!!
	int llama = 0;
}

void funct2(int q)
{
}
```

funct1() 안에 선언된 count 변수는 `지역 사용 범위`를 가지며 링크가 없다. 자동 변수인 llama와 마찬가지로 func1() 에서만 사용가능하지만,
funct1() 함수가 실행되고 있지 않을 때에도 count 변수는 메모리에 계속해서 존재한다.

one_file 은 `내부 링크`를 가지기 때문에, 이 코드가 담겨 있는 파일안에서만 사용할 수 있다. <br>
global 은 `외부 링크`를 가지기 때문에, 프로그램을 구성하는 다른 파일에서도 사용할 수 있다.

`외부 링크`를 가지는 정적 변수를 만드려면, 어떠한 블록에도 속하지 않는 완전한 바깥에 그것을 선언하자. <br>
`내부 링크`를 가지는 정적 변수를 만드려면, 어떠한 블록에도 속하지 않는 바깥에서 그것을 선언하되, `static`이라는 기억 공간 제한자를 선언 앞에 붙이자.
`링크가 없는 정적 변수`를 만드려면, `static`이라는 제한자를 사용해서 블록 안에서 그것을 선언하자.

#### 제로 초기화(zero-initialized)
모든 정적 변수들은 초기화되지 않은 정적 변수들의 모든 비트가 0으로 세팅된다.

#### static 키워드 의미
링크가 없는 정적 변수를 지시하기 위해서는 지역 선언과 동시에 `static`를 같이 붙이고, 함수 밖에서 선언되었을 때에는 `static`이 `내부 링크`를 의미한다.
-> `키워드 오버로딩`은 문맥과 정황에 따라 정확한 의미가 결정된다.

| 기억 공간 | 기억 존속 시간 | 사용 범위 | 링크 | 선언 방법 |
| -------- | ------------ | -------- | ----- | ------ |
| 자동          | 자동 | 블록 | 없음 | 블록 안에 선언 |
| 레지스터      | 자동 | 블록 | 없음 | 블록 안에 `register` 사용 |
| 링크 없는 정적 | 정적 | 블록 | 없음 | 블록 안에 `static` 사용 |
| 외부 링크 정적 | 정적 | 파일 | 외부 | 함수의 바깥에 선언 |
| 내부 링크 정적 | 정적 | 파일 | 내부 | 함수의 바깥에 `static` 사용 |

#### 정적 변수 초기화
정적 변수는 제로 초기화될 수 있고 상수 표현 초기화될 수 있으며, 동적 초기화될 수 있다.
C++ 코드에서는 `0`으로 표현되는 `null 포인터`는 0이 아닌 내부 표현을 지닐 수 있기 때문에 `포인터 변수`는 그 변수에 대하여 초기화될 것이다.
구조체의 멤버 변수들은 제로 초기화되고, 모든 패딩 비트는 0에 맞춰진다.

`제로 초기화`와 `상수 표현 초기화`를 합쳐서 `정적 초기화`라고 부른다. 컴파일러가 파일을(또는 변환 유닛을) 처리할 때 변수가 초기화된다는 의미이다.
`동적 초기화`는 그 변수가 이후에 초기화된다는 것을 의미한다.


```cpp
int x; // 제로 초기화
int y = 5; // 상수 표시 초기화
int z = 13 * 13; // 상수 표시 초기화
const double pi = 4.0 * atan(1.0); // 동적 초기화
int enough = 2 * sizeof (long) + 1; // 상수 표현 초기화
```

pi를 초기화시키기 위해서는 atan()을 불러내야 하는데, 함수가 연결되어 프로그램이 시행될 때까지 기다려야한다.


### 정적 존속 시간, 외부 링크
외부 변수는 외부에서 정의되기 때문에 다른 외부 함수와 연계된다.

#### 단일 정의 원칙
C++에서는 하나의 변수에 대하여 오직 하나의 정의를 부여하는 `단일 정의 원칙`을 명시하고 있다.
- 선언을 정의하는 것 또는 단순하게 정의로, 대입되는 변수에 대하여 저장소를 제공한다.
- `참조 선언` 혹은 단순히 선언하는 것, 기존의 변수를 의미하므로 저장소를 생성하지는 않는다.

`참조 선언`은 `extern`이라는 키워드를 사용하고 초기화를 제공하지 않는다.
그렇지 않은 경우에는 선언은 정의이며 저장소가 대입되도록 한다.

```cpp
double up;            // 정의, up은 0
extern int blem;      // blem은 다른 지역에서 정의된다.
extern char gr = 'z'; // 초기화되므로 선언이다.
```

만약 여러 파일에서 외부 변수가 사용될 경우, 오직 한 개의 파일이 그 변수에 대한 정의를 지닐 수 있다.(유일 정의 원칙).
그 변수를 사용하는 다른 모든 파일들은 그 변수를 `extern`이라는 키워드를 사용해서 선언해 줄 필요가 있다!

```cpp
file01.cpp

extern int cats = 20; // 초기화되므로 정의에 해당
int dogs = 22;        // 정의에 해당
int fleas;            // 정의에 해당


file02.cpp

extern int cats;     // 그들이 사용하기 때문에 정의에 해당되지 않는다.
extern int dogs;     // extern에 해당되며 초기화되지 않는다.

file98.cpp

extern int cats;
extern int dogs;
extern int fleas;    // 벼룩 변수를 재선언하지 않기 때문에 접속할 수 없다.
```

`유일 정의 원칙`은 주어진 이름에 오직 하나의 변수만이 가능하다는 것을 의미하지 않는다.
다른 함수에서 정의된 자동 변수는 별개의 변수이며, 서로 독립적임과 동시에 각자 고유의 개별적인 주소를 지닌다.
`지역 변수`는 동일한 이름의 전역 변수를 숨길 수 있다.

`::` 사용 범위 결정 연산자를 제공함으로써, 이 연산자를 변수 이름 앞에 붙이면 그 변수의 전역 버전을 사용하라는 뜻이 되게 된다.


#### 전역과 지역 (머가 더 좋은가?)
전역 변수처럼 접근이 쉬운 것이 오히려 프로그램의 신뢰성을 떨어뜨린다.
데이터에 대한 불필요한 접근을 잘 막으면 막을수록 데이터의 `무결성(정보나 데이터가 변형되거나 손상되지 않도록 보장하는 것)`이 보존된다.
대부분의 경우에는 데이터를 무차별적으로 전역 변수로 만들기보다는 지역 변수로 만들어 꼭 필요한 함수에만 데이터를 전달하는 것이 좋다.

전역 변수가 유용할 때도 있는데, 여러 함수가 공통으로 사용하는 데이터 블록을 만들 수 있다.
`const`키워드를 사용하면 상수 데이터가 변경되지 않도록 할 수 있기 때문에, 전역 변수는 특히 상수 데이터를 나타내는 데 유용하다.

```cpp
const char * const month[12] = 
{
	"January", "February", "March", "April", "May", "June", "July",
	"August", "September", "October", "November", "December"
};

첫 번째 const는 그 문자열들이 변경되는 것을 막고,
두 번째 const는 배열에 들어 있는 각각의 포인터가 최초에 지시한 문자열을 계속 지시하도록 만든다.
```

### 정적 존속 기간, 내부 링크
`static` 제한자를 적용하면 `내부 링크`를 부여한다.
내부 링크 변수는 그 변수를 포함하고 있는 파일에서만 사용할 수 있지만, 외부 링크 변수는 다른 파일에서도 사용이 가능하다.

다중 파일 프로그램에서 단 하나의 파일에 하나의 이름으로 외부 변수 선언이 가능하다.
다른 파일에서 그 변수를 사용하기 위해서는 `extern`선언을 해야만 한다.

### 정적 기억 존속 시간, 링크 없음
블록 안에서 `static`을 사용하면, static이 지역 변수를 정적 기억 존속 시간을 갖게 만든다.
이 변수는 블록 안에서만 알려지지만 그 블록이 활동하지 않는 동안에도 계속 존재한다는 것을 의미한다.
그러므로 정적 지역 변수는 함수의 호출과 호출 사이에서도 값을 보존할 수 있다.

`정적 지역 변수`를 초기화하면, 프로그램은 시작할 때 1번만 초기화된다.
그 이후에 이루어지는 함수 호출들은 자동 변수와는 달리 그 변수를 다시 초기화하지 않는다.

### 제한자
기억 공간 제한자(storage class specifier)와 cv 제한자라고 부르는 몇 가지 C++ 키워드가 기억 공간에 대해서 추가 정보를 제공한다.
- auto(C++11 에서는 제한자에서 빠진다)
- register
- static
- extern
- thread_local(C++에서 추가됨)
- mutable

제한자를 하나만 사용할 수 있지만 `thread_local`만은 static 또는 extern과 함께 사용할 수 있다.
C++11 에서는 `auto`는 자동 형변환에 사용되고, `register`키워드는 레지스터 기억 공간을 지정하는 선언에 사용되었다가 C++11부터는 단순하게 `자동 변수`라는 것을 의미하는 명시적 방법이 되었다.

`static`은 파일 범위 선언에 사용될 때 `내부 링크`, 지역 선언에 사용될 때 지역 변수를 위한 정적 기억 존속 시간을 가리킨다.
`extern`은 참조 선언을 나타낸다. 그 선언은 다른 곳에 이미 정의되어 있는 변수를 참조한다.

`thread_local`은 변수의 존속 시간이 변수를 포함하는 쓰레드의 존속 시간이다.
정적 변수의 존속 시간은 프로그램의 존속 시간과 같지만, `thread_local`변수는 존속 시간이 쓰레드의 존속 시간과 같다.

### cv 제한자
- const
- volatile

메모리가 일단 초기화된 후에는 프로그램이 그 메모리를 변경할 수 없다는 뜻이다.

`volatile`은 프로그램 코드가 변경하지 않더라도 특정 메모리 위치에 있는 값이 변경될 수 있다는 것을 나타낸다.
이 키워드의 목적은 컴파일러의 최적화 능력을 개선하는 것이다.
```cpp
컴파일러가 고작 몇 개의 구문 안에서 어떤 변수의 값이 2번 사용되고 있다는 것을 발견했다고 했을 때

컴파일러는 프로그램이 그 값을 2번 조사하게 하지 않고, 레지스터에서 직접 그 값을 캐시할 수 있다.
이러한 최적화는 그 변수가 2번 사용되는 동안에 값이 변하지 않는다고 가정한다.

어떤 변수를 volatile로 선언하지 않으면 컴파일러가 이러한 최적화를 자유로이 수행할 수 있지만?
volatile로 선언하면 컴파일러가 이러한 최적화를 수행하지 못하게 막는다.
```

### mutable
특정 구조체(또는 클래스)가 `const`로 선언되어 있다 하더라도 그 구조체의 특정 멤버를 변경할 수 있음을 나타내는 데 사용한다.

### const에 대한 보충
C++에서는 const 제한자가 디폴트 기억 공간을 약간 바꾼다.
전역 변수는 외부 링크를 갖도록 디폴트로 내정되어 있지만, const 전역 변수는 내부 링크를 갖도록 디폴트로 내정된다.

C++ const 정의를 마치 static 제한자가 사용된 것처럼 취급한다.
```cpp
const int fingers = 10; // static const int fingers; 와 같다.

const char * warning = "Wak!";
```
하나의 파일만이 위와 같은 선언을 가질 수 있고, 다른 파일들은 모두 `extern`키워드를 사용해야 한다.
외부적으로 정의된 const 데이터는 내부 링크를 갖기 때문에 모든 파일에 같은 선언을 사용할 수 있다.

또한 내부 링크는 각 파일들이 상수 집합을 공유하지 않고 자신만의 상수 집합을 따로 가진다는 것을 의미한다.
각각의 정의는 그들이 들어 있는 파일에 개별적이다.

상수 정의들을 헤더 파일에 넣는 것이 좋은 이유가 동일한 헤더 파일을 2개의 소스 코드 파일에 넣으면?
두 파일은 동일한 상수 집합을 갖게 된다.

어떠한 이유로 상수를 외부 링크로 만들려면 `extern`키워드를 사용하여 디폴트로 되어 있는 내부 링크를 가질 수 있다.
```cpp
extern const states = 50; // 외부 링크
```
이 상수를 사용하는 모든 파일에서는 `extern`키워드를 사용하여 그 상수를 선언해야 한다.
다만 위의 변수는 좀 다른데, extern const 값은 초기화할 수 있게 된다.
실제로 const 데이터는 초기화를 요구하기 때문에 반드시 초기화해야 한다.

함수나 블록 안에서 const를 선언하면, 그것은 블록 사용 범위를 가지게 된다.
프로그램이 블록 안에 있는 코드를 실행하고 있을 때에만 그 상수를 사용할 수 있다는 뜻이고
다른 어딘가에 정의된 상수와 이름이 충돌하지 않을까 걱정할 필요 없이, 함수나 블록 안에서 마음대로 상수를 만들 수 있다는 뜻이다.

### 함수와 링크
함수 역시 링크 속성을 가진다. C++는 하나의 함수 안에서 다른 함수를 정의할 수 없다.
모든 함수는 자동적으로 정적 기억 존속 시간을 가진다. 프로그램이 실행되는 동안 모든 함수가 계속 존재한다는 것을 의미한다.
기본적으로 함수는 `외부 링크`를 가진다. 여러 파일이 함수를 공유할 수 있다는 뜻이다.

프로그램이 어떤 파일에 들어 있는 함수를 찾는다면, 그 파일은 프로그램의 일부로서 컴파일되고 있는 파일들 중의 하나이거나,
링커에 의해서 탐색되는 라이브러리 파일이다.

`static`키워드를 사용해서 함수에 `내부 링크`를 부여할 수 있다. 그 함수의 사용 범위를 하나의 파일로 제한한다.
이 키워드는 함수 원형과 함수 정의에 같이 적용한다.
```cpp
static int private(double x);

static int private(double x)
{
}
```
이 함수는 그 파일에만 알려진다는 것을 의미한다.

C++은 `단일 정의 규칙`으로 인라인이 아닌 모든 함수에 대해서 프로그램은 정확히 하나의 정의만을 가진다.
`외부 링크`를 가지는 함수에 대해서 다중 파일 프로그램의 파일 하나만 그 함수 정의를 가질 수 있다는 것을 말한다.
그러나 그 함수를 사용하는 각각의 파일은 그 함수의 원형을 가져야 한다!

`인라인`함수는 이 규칙을 따르지 않는다. 헤더 파일에 인라인 함수 정의들을 넣는 것이 허용된다.
그 헤더 파일을 포함하는 각각의 파일들은 모두 인라인 함수 정의를 갖게 된다.
C++은 하나의 특정 함수를 위한 인라인 정의가 모두 동일할 것을 요구한다.

### 언어 링크
C++에서는 같은 이름의 함수를 여러 개 가질 수 있으므로, 이들이 모두 서로 다른 기호 이름으로 변환되어야 한다.
C++ 컴파일러는 오버로딩된 함수들에 대해서 서로 다른 기호 이름을 생성하기 위해 `맹글링(name mangling)` 또는 `이름 장식(name decoration)` 과정을 거친다.
spiff(int) -> _spiff_i로, spiff(double, double) -> _spiff_d_d로 변환 할 수 있다.
이러한 접근 방식을 `C++ 언어 링크(C++ language linkage)`라고 한다.

```cpp
extern "C" void spiff(int);   // C 프로토콜을 사용하여 이름을 찾는다.
extern void spoff(int);       // C++ 프로토콜을 사용하여 이름을 찾는다.
extern "C++" void spaff(int); // C++ 프로토콜을 사용하여 이름을 찾는다.
```

1. C언어 링크를 사용
2. C++ 언어 링크이지만 디폴트 사용 방법
3. C++ 언어 링크이면서 명시적 사용 방법

### 기억 공간 형식과 동적 대입
자동 메모리와 달리, 동적 메모리는 `LIFO`	가 아니다. 대입 순서와 해제 순서가 `new`와 `delete`를 언제 어떻게 사용하느냐에 달려 있다.
일반적으로 컴파일러는 메모리 공간을 정적 변수를 위한 공간(이 공간은 더 세분화가 될 수 있음), 자동 변수를 위한 공간, 동적 변수를 위한 공간으로 나누어 사용한다.

`기억 공간 형식`이라는 개념이 동적 메모리에 적용되지 않지만, 동적 메모리를 추적하는 데 사용되는 자동 및 정적 포인터 변수에는 적용된다.

#### new 연산자를 이용한 초기화
```cpp
int * pi = new int (6);
double * pd = new double (99.99);
```
괄호를 이용해 초기 값을 설정할 수 있다.
순차적인 구조체나 변수를 초기화하기 위해서는 `C++11`에서만 가능하고 중괄호를 이용한 `리스트 초기화`를 사용해야 한다.
```cpp
struct where
{
	double x;
	double y;
	double z;
};

where * one = new where { 2.5, 5.3, 7.2 };

int * ar = new int [4] { 2, 4, 6, 7 };
```

C++11에서는 단일 값을 가지는 변수에 대해서도 중괄호를 이용한 초기화가 가능하다.
```cpp
int * pin = new int {6};
double * pdo = new double {99.99};
```

#### new가 실패하는 경우
new는 필요한 메모리의 양을 확보할 수 없는 경우가 발생할 수 있다.
과거의 C++은 new가 null 포인터를 리턴함으로써 문제를 처리했지만 최근에는 new가 `std::bad_alloc` 예외를 반환한다.

#### new: 연산자들, 함수들, 대체 함수들
new와 new[] 연산자는 다음 2개의 함수를 호출한다.
```cpp
void * operator new(std::size_t);   // new에서 호출
void * operator new[] (std::size_t) // new[]에서 호출
```

대입 함수라고 부르고, 대입 함수는 전역 이름 공간의 일부이다.
```cpp
void operator delete(void *);
void operator delete[](void *);
```

`std::size_t`는 typedef이고 기본 선언은 다음과 같다.
```cpp
int * pi = new int;

다음과 같이 변환할 수 있다.
int * pi = new(sizeof(int));

int * pa = new int[40];
int * pa = new(40 * sizeof(int));
>> new 연산자를 이용한 선언은 초기 값을 설정할 수 있다.
new 연산자를 사용하면 단순히 new() 함수를 호출하는 것보다 더 많은 일을 할 수 있다.

delete pi;
delete (pi);
```

#### 위치 지정 new 연산자
일반적으로 new 연산자는 사용자가 요청한 메모리 크기를 충분히 다룰 수 있을 만큼의 메모리 블록을 힙에서 찾는다.
그런데 new 연산자는 사용할 위치를 사용자가 지정할 수 있는 `위치 지정 new`라는 1가지 변형이 있다.

프로그래머는 메모리 관리 절차를 설정하거나 특정 주소를 통해 접근하는 하드웨어를 다루고, 특정 메모리 위치에 있는 객체를
생성하는 데에 이 기능을 사용할 수 있다.

```cpp
#include <new>
struct chaff
{
	char dross[20];
	int slag;
};

char buffer1[50];
char buffer2[500];

int main()
{
	chaff *p1, *p2;
	int *p3, *p4;

	// new 일반 형식
	p1 = new chaff;     // 구조체를 힙에 놓는다.
	p3 = new int[20];   // int 배열을 힙에 놓는다.

	// 위치 지정 new
	p2 = new (buffer1) chaff;   // 구조체를 buffer1에 놓는다.
	p4 = new (buffer2) int[20]; // int 배열을 buffer2에 놓는다.
}
```
- 위치 지정 new는 힙이 아닌 다른 공간에 놓는다는 것을 의미한다.
- 위치 지정 new는 이전에 사용된 것과 동일한 블록을 사용할 수 있다. (다만 메모리 관리 부담을 프로그래머에게 떠넘긴다.)
- delete를 사용하는 것과 사용하지 않는 것의 관계가 있다. (만약에 위지 지정 new를 정적 배열에 놓은 경우에는 delete가 필요없다.)

`delete`는 보통의 new에 의해 대입된 힙 메모리에 지시하는 포인터에만 사용할 수 있다.

#### new 배치 형식
일반적인 new가 하나의 매개변수를 가지고 new 함수를 불러오듯이 표준배치 new는 2가지 매개변수를 가지고 new 함수를 불러온다.
```cpp
int * pi = new int;          // new (sizeof(int)) 호출
int * pi = new (buffer) int; // new (sizeof(int), buffer) 호출

int * p3 = new (buffer) int[40]; // new (40 * sizeof(int), buffer) 호출
```

## 이름 공간
- 변수
- 함수
- 구조체
- 열거체
- 클래스

클래스 멤버와 구조체 멤버를 이름을 통해 참조할 수 있다.
프로그래밍 프로젝트의 규모가 커짐에 따라, 이름 충돌 가능성이 높아지고 있다.

### 구식 C++ 이름 공간

`선언 영역` <br>
선언을 할 수 있는 영역으로 전역 변수는 모든 함수의 바깥에서 선언할 수 있고, 그 변수의 선언 영역은 그것이 선언된 파일이다.
어떤 변수를 함수 안에서 선언한다면 그 변수의 선언 영역은 그것이 선언된 블록이다.

`잠재 사용 범위` <br>
어떤 변수의 잠재 사용 범위는 그 변수를 선언한 지점부터 선언 영역의 끝까지다.
잠재 사용 범위에서 변수가 보이지 않을 수 있는데, 어떤 변수는 내포된 선언 영역에 같은 이름으로 선언된 또 다른 변수에 의해 앞이 가려질 수 있다.
변수를 실제로 볼 수 있는 프로그램의 영역을 `사용 범위(scope)`라고 한다.

하나의 함수에서 선언된 지역 변수는 다른 함수에서 선언된 지역 변수와 충돌하지 않으며,
각각의 선언 영역은, 다른 선언 영역에서 선언된 이름과는 관련이 없는 독립된 이름을 선언할 수 있다.

### 새로운 이름 공간 기능
새로운 종류의 선언 영역을 정의함으로써 이름이 명명된 이름 공간을 만들 수 있는 기능이 C++에 추가 되었다.
`이름을 선언하는 영역`을 따로 제공하는 것인데, 하나의 이름 공간에 속한 이름은 동일한 이름으로 다른 이름 공간에 선언된 이름과 충돌하지 않는다.

이름 공간은 전역 위치에 또는 다른 이름 공간 안에도 놓일 수 있지만 블록 안에는 놓을 수 없다.
그러므로 하나의 이름 공간에 선언된 이름은 기본적으로 `외부 링크`를 가지게 된다.

사용자가 정의하는 이름 공간 외에 전역 이름 공간이라는 또 하나의 이름 공간이 있다.
이것은 파일 수준의 선언 영역에 해당한다. 지금까지 전역 변수라고 불러 왔던 것들은 `전역 이름 공간`의 일부라고 말할 수 있다.

이름 공간은 항상 열려 있기 때문에, 기존의 이름 공간에 새로운 이름을 추가할 수 있다.

#### 주어진 이름 공간에 속해 있는 이름에 접근하는 방법
`사용 범위 결정 연산자 ::`를 사용해서 어떤 이름을 주어진 이름 공간으로 제한(qualify)하는 것이다.
```cpp
Jack::pail = 12.34;
Jill::Hill mole;
Jack::fetch();
```

### using 선언과 using 지시자
사용할 때마다 매번 이름을 제한한다는 것은 성가시므로, C++은 이름 공간에 속해 있는 이름을 건편하게 사용할 수 있는 `using 선언`과 `using 지시자`를 제공한다.

#### using 선언
제한된 이름 앞에 키워드 `using`을 붙인다. <br>
만약에 어떤 함수가 오버로딩되어 있다면, using 선언을 하나만 사용해도 오버로딩된 모든 버전의 함수들을 불러들인다.

```cpp
using Jill::fetch;
```
이 선언을 한 이후에는 Jill::fetch 대신에 fetch라는 이름을 사용할 수 있다.

```cpp
namespace Jill
{
	double bucket(double n) { }
	double fetch;
	struct Hill { ... };
}

char fetch;
int main()
{
	using Jill::fetch;
	double fetch;   // error , using 선언ㅇ은 그 이름을 지역 선언 영역에 추가하기 때문에 또 하나의 지역 변수를 만들지 못하게 한다.
	cin >> fetch;   // Jill::fetch에 저장
	cin >> ::fetch; // 전역 fetch에 저장
}
```

`using 선언`은 외부 위치에 놓으면, 그 이름이 전역 이름 공간에 추가된다.
다만 using 선언은 하나의 이름만을 사용할 수 있게 만든다.

`using 지시자`는 하나의 이름 공간 앞에 `using namespace`라는 키워드를 붙인다.
이렇게 하면 사용 범위 결정 연산자를 사용하지 않고도 그 이름 공간에 속한 모든 이름을 사용할 수 있게 된다.
```cpp
using namespace Jack; // Jack에 속한 모든 이름을 사용할 수 있게 만든다.
```

어떤 특별한 함수 안에 넣으면, 그 이름들은 그 함수 안에서만 사용할 수 있다.

```cpp
using jack::pal;
using jill::pal;
pal = 4; // 모호함이 발생하므로 두 using 선언을 함께 사용하는 것을 허용하지 않는다.
```

핵심은, `using 지시자`보다는 `using 선언`을 사용하는 것이 더 안전하다. <br>
`using 지시자`는 필요하지 않은 이름까지 포함하여 모든 이름을 추가시킨다.

#### Alias
어떤 이름 공간에 대한 대용 이름(alias, 별칭)을 만들 수 있다.

```cpp
namespace MEF = myth::elements::fire;
using MEF::flame;

이 기법을 사용하면 중첩된 이름 공간을 보다 간단하게 사용할 수 있게 된다.
```


#### 이름을 명명하지 않은 이름 공간
이름 공간의 이름을 생략하면 이름을 명명하지 않은 이름 공간이 만들어진다.
```cpp
namespace
{
	int ice;
	int bandycoot;
}
```
이렇게 사용하면 `내부 링크`를 가지는 정적 변수 대신 사용할 수 있게 된다.

```cpp
static int counts; // 정적 기억 공간, 내부 링크

대신에

namespace
{
	int counts;    // 정적 기억 공간, 내부 링크
}
```

### 이름 공간의 미래
가이드 라인이 있다.

- 외부 전역 변수를 사용하지 말고, 이름이 명명된 이름 공간에 있는 변수를 사용하자.
- 정적 전역 변수를 사용하지 말고, 이름이 명명되지 않은 이름 공간에 있는 변수를 사용하자.
- 현재 C++은 표준 라이브러리 함수들을 `std`라는 이름 공간에 넣을 것을 요구하고 있다.
- `using 지시자`를 헤더 파일에 사용하지 않는다.
- `사용 범위 결정 연산자` 또는 `using 선언`을 사용하여 이름을 선택적으로 사용하자.
- `using 선언`에 대해 전역 범위 대신 선택적으로 지역 범위를 사용하자.

이름 공간을 사용하는 주된 동기는 대규모 프로그래밍 프로젝트의 관리를 간단하게 하기 위한 것이다.