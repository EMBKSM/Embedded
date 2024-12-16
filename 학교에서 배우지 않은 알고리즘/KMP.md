# KMP 알고리즘

KMP(Knuth-Morris-Pratt) 알고리즘은 문자열 탐색 알고리즘으로, 주어진 텍스트에서 특정 패턴을 효율적으로 찾는 방법입니다. 이 알고리즘은 Knuth, Morris, Pratt 세 명의 이름을 따서 명명되었으며, 시간 복잡도가 O(N+M)으로 효율적 (N은 텍스트의 길이, M은 패턴의 길이)

Brute force 방식과는 달리, 이미 매칭에 성공했던 부분의 정보를 재활용하여 불필요한 탐색을 줄이는 것이 특징

---

## 핵심 개념

### 1. **pi 배열**
pi 배열은 패턴 문자열에서 prefix(접두사)와 suffix(접미사)가 일치하는 최대 길이를 저장함  
즉, `pi[i]`는 패턴의 0부터 i까지의 부분 문자열 중에서 prefix와 suffix가 동일한 가장 긴 문자열의 길이이다

#### 예시:
패턴이 `"ababc"`라면, pi 배열은 다음과 같이 계산된다:
- 부분 문자열 `"a"`: prefix == suffix → 없음 → `pi[0] = 0`
- 부분 문자열 `"ab"`: prefix == suffix → 없음 → `pi[1] = 0`
- 부분 문자열 `"aba"`: prefix == suffix → `"a"` → `pi[2] = 1`
- 부분 문자열 `"abab"`: prefix == suffix → `"ab"` → `pi[3] = 2`
- 부분 문자열 `"ababc"`: prefix == suffix → 없음 → `pi[4] = 0`

결과적으로, pi 배열은 `[0, 0, 1, 2, 0]`이다

### 2. **탐색 과정**
KMP 알고리즘은 두 가지 단계로 이루어진다:
1. **pi 배열 생성 (전처리 단계):** 패턴을 분석하여 pi 배열을 생성
2. **탐색:** 텍스트를 탐색하면서 pi 배열을 활용해 일치 여부를 확인합니다. 일치가 실패했을 때, pi 배열을 참고하여 이동 거리를 조정함으로써 불필요한 비교를 피함

---

## Brute force의 한계
Brute force 방식에서는 패턴이 텍스트와 일치하지 않을 경우, 탐색을 처음부터 다시 시작합니다. 즉, 이미 비교했던 정보를 낭비하게 됨

---

## KMP 알고리즘의 장점
- **효율성:** 이미 비교했던 부분 문자열의 정보를 재활용하여 불필요한 비교를 최소
- **시간 복잡도:** O(N+M)으로, 텍스트와 패턴의 길이에 선형적으로 비례
- **안정성:** 동일한 입력에서 항상 같은 속도로 동작

---

## 코드 예제 (C++)

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// pi 배열 생성 함수 (전처리 단계)
vector<int> computePi(const string& pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);
    int j = 0; // 접두사의 끝을 가리키는 포인터

    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1]; // 불일치 시 이전 접두사로 이동
        }
        if (pattern[i] == pattern[j]) {
            ++j;
            pi[i] = j;
        }
    }
    return pi;
}

// KMP 탐색 함수
void kmpSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> pi = computePi(pattern);
    int j = 0; // 패턴의 위치 포인터

    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1]; // 불일치 시 이전 접두사로 이동
        }
        if (text[i] == pattern[j]) {
            if (j == m - 1) { // 패턴 전체가 매칭된 경우
                cout << "패턴 발견: " << i - m + 1 << "번째 인덱스에서 시작\n";
                j = pi[j]; // 다음 탐색 준비
            } else {
                ++j;
            }
        }
    }
}

// 메인 함수
int main() {
    string text, pattern;
    cout << "텍스트 입력: ";
    cin >> text;
    cout << "패턴 입력: ";
    cin >> pattern;

    kmpSearch(text, pattern);

    return 0;
}
