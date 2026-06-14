#include <iostream>
#include <string>
#include <vector>
#include "blockedState.h"
using namespace std;

// BlockedState.cpp
// Здесь реализуется поведение заблокированного места.
//
// Что нужно реализовать:
// 1. reserve запрещен.
// 2. purchase запрещен.
// 3. cancel запрещен.
// 4. unblock переводит место в FreeState.
//
// Главная цель:
// Не дать пользователю купить технически недоступное место.