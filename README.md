# C++ exam

The fall 2022 exam from the "C++ for programmers" (INFT2503) course.

Counts towards 100% of the final grade in the subject.

[![CMake build](https://github.com/Marko19907/CPP-exam/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/Marko19907/CPP-exam/actions/workflows/build.yml)


## Tasks


### Task 1

Create the necessary functions so that the following:

```C++
cout << concat("hello", "world") << endl;
cout << concat(1, 2) << endl;
cout << concat({"a", "b", "c"}) << endl;
```

Outputs this:

```
helloworld
12
abc
```


### Task 2

Create the necessary classes so that the following:

```C++
vector<unique_ptr<Animal>> animals;
animals.emplace_back(make_unique<Elephant>());
animals.emplace_back(make_unique<Elephant>());
animals.emplace_back(make_unique<Pig>());

for(auto &a : animals)
  cout << a->makeNoise() << endl;
```

Outputs this:

```
Toot!
Toot!
Honk!
```


### Task 3

Create the necessary functions so that the following:

```C++
cout << map_f<int, int>({1, 2, 3}, [](int a){return a * 2;}) << endl;
cout << map_f<float, float>({1, 2.3, 3}, [](float a){return a /2;}) << endl;
cout << map_f<string, string>({"hello", "world"}, [](string s){return s + ".";}) << endl;
cout << map_f<string, int>({"hello", "world"}, [](string s){return s.size();}) << endl;
```

Outputs this:

```
{ 2, 4, 6 }
{ 0.5, 1.15, 1.5 }
{ hello., world. }
{ 5, 5 }
```


### Task 4

Create the necessary classes so that the following:
 
```C++
Matrix<int> m_a({{1, 2}, {3, 4}, {5, 6}});
Matrix<int> m_b({{1, 2, 3}, {4, 5, 6}});

cout << m_a << endl;
cout << m_b << endl;
cout << m_a * m_b << endl;
cout << m_b * m_a << endl;


Matrix<int> m_c({{1, 2}});
Matrix<int> m_d({{2}, {2}});

cout << m_c * m_d << endl;
cout << m_d * m_c << endl;
```

Outputs this:

```
[ 1 2 ]
[ 3 4 ]
[ 5 6 ]

[ 1 2 3 ]
[ 4 5 6 ]

[ 9 12 15 ]
[ 19 26 33 ]
[ 29 40 51 ]

[ 22 28 ]
[ 49 64 ]

[ 6 ]

[ 2 4 ]
[ 2 4 ]
```
