#include "tests/test_treap.h"

#include <cstring>
#include <iostream>
#include <stdexcept>

#include "treap.h"

namespace {
void demonstrate_treap() {
  std::cout
      << "1. Create a treap with seed=52 (priorities range: 0 to 1024):\n";
  lab1::treap t1(52, 0, 1024);

  std::cout << "\n2. Insert elements:\n";
  t1.insert("Alice", 10);
  std::cout << "   Inserted ('Alice', 10). Current top: " << t1.top()
            << " (key: " << t1.top_priority() << ")\n";

  t1.insert("Bob", 20);
  std::cout << "   Inserted ('Bob', 20). Current top: " << t1.top()
            << " (key: " << t1.top_priority() << ")\n";

  t1.insert("Charlie", 5);
  std::cout << "   Inserted ('Charlie', 5). Current top: " << t1.top()
            << " (key: " << t1.top_priority() << ")\n";

  std::cout << "\n3. Treap size: " << t1.size() << std::endl;

  std::cout << "\n4. Search for elements:\n";
  int key_to_find = 20;
  std::optional<const char*> result = t1.find(key_to_find);
  std::cout << "   Search for key " << key_to_find << ": "
            << (result ? *result : "not found") << std::endl;

  key_to_find = 99;
  result = t1.find(key_to_find);
  std::cout << "   Search for key " << key_to_find << ": "
            << (result ? *result : "not found") << std::endl;

  std::cout << "\n5. Delete element with key 5:\n";
  bool is_disposed = t1.dispose(5);
  std::cout << "   Deletion result: " << (is_disposed ? "success" : "failure")
            << ". New size: " << t1.size() << std::endl;
  std::cout << "   New top: " << t1.top() << " (priority: " << t1.top_priority()
            << ")\n";

  std::cout << "\n6. Pop the top element:\n";
  t1.pop();
  std::cout << "   New top: " << t1.top() << " (priority: " << t1.top_priority()
            << ")\n";
  std::cout << "   Size after pop: " << t1.size() << std::endl;
  std::cout << "\n7. Merge two treaps:\n";

  lab1::treap t2(123, 0, 1024);
  t2.insert("Dave", 1000);
  t2.insert("Eve", 993);
  std::cout << "   Created second treap. Its top: " << t2.top()
            << " (priority: " << t2.top_priority() << ")\n";

  t1.merge(&t2);
  std::cout << "   Merge result:\n";
  std::cout << "   Top of merged treap: " << t1.top()
            << " (priority: " << t1.top_priority() << ")\n";
  std::cout << "   Size of merged treap: " << t1.size() << std::endl;

  std::cout << "   Size of original t1: " << t1.size() << std::endl;
  std::cout << "   Size of original t2: " << t2.size() << std::endl;

  std::cout << "\n8. Test copying and assignment:\n";
  lab1::treap t3(t1);
  std::cout << "   Size of copy t3: " << t3.size() << std::endl;

  lab1::treap t4;
  t4 = t3;
  std::cout << "   Size of assigned t4: " << t4.size() << std::endl;

  t4.insert("Frank", 30);
  std::cout << "   After inserting into t4. Its size: " << t4.size()
            << ", size of original t3: " << t3.size() << std::endl;
}

void demonstrate_treap_ru() {
  std::cout << "1. Создание декартового дерева с seed=52 (приоритеты в "
               "диапазоне: 0 до 1024):\n";
  lab1::treap t1(52, 0, 1024);

  std::cout << "\n2. Вставка элементов:\n";
  t1.insert("Алиса", 10);
  std::cout << "   Вставлено ('Алиса', 10). Текущий верхний элемент: "
            << t1.top() << " (ключ: " << t1.top_priority() << ")\n";

  t1.insert("Боб", 20);
  std::cout << "   Вставлено ('Боб', 20). Текущий верхний элемент: " << t1.top()
            << " (ключ: " << t1.top_priority() << ")\n";

  t1.insert("Чарли", 5);
  std::cout << "   Вставлено ('Чарли', 5). Текущий верхний элемент: "
            << t1.top() << " (ключ: " << t1.top_priority() << ")\n";

  std::cout << "\n3. Размер дерева: " << t1.size() << std::endl;

  std::cout << "\n4. Поиск элементов:\n";
  int key_to_find = 20;
  std::optional<const char*> result = t1.find(key_to_find);
  std::cout << "   Поиск ключа " << key_to_find << ": "
            << (result ? *result : "не найдено") << std::endl;

  key_to_find = 99;
  result = t1.find(key_to_find);
  std::cout << "   Поиск ключа " << key_to_find << ": "
            << (result ? *result : "не найдено") << std::endl;

  std::cout << "\n5. Удаление элемента с ключом 5:\n";
  bool is_disposed = t1.dispose(5);
  std::cout << "   Результат удаления: " << (is_disposed ? "успех" : "неудача")
            << ". Новый размер: " << t1.size() << std::endl;
  std::cout << "   Новый верхний элемент: " << t1.top()
            << " (приоритет: " << t1.top_priority() << ")\n";

  std::cout << "\n6. Удаление верхнего элемента:\n";
  t1.pop();
  std::cout << "   Новый верхний элемент: " << t1.top()
            << " (приоритет: " << t1.top_priority() << ")\n";
  std::cout << "   Размер после удаления: " << t1.size() << std::endl;
  std::cout << "\n7. Объединение двух деревьев:\n";

  lab1::treap t2(123, 0, 1024);
  t2.insert("Дэйв", 1000);
  t2.insert("Ева", 993);
  std::cout << "   Создано второе дерево. Его верхний элемент: " << t2.top()
            << " (приоритет: " << t2.top_priority() << ")\n";

  t1.merge(&t2);
  std::cout << "   Результат объединения:\n";
  std::cout << "   Верхний элемент объединенного дерева: " << t1.top()
            << " (приоритет: " << t1.top_priority() << ")\n";
  std::cout << "   Размер объединенного дерева: " << t1.size() << std::endl;

  std::cout << "   Размер исходного t1: " << t1.size() << std::endl;
  std::cout << "   Размер исходного t2: " << t2.size() << std::endl;

  std::cout << "\n8. Тестирование копирования и присваивания:\n";
  lab1::treap t3(t1);
  std::cout << "   Размер копии t3: " << t3.size() << std::endl;

  lab1::treap t4;
  t4 = t3;
  std::cout << "   Размер присвоенного t4: " << t4.size() << std::endl;

  t4.insert("Фрэнк", 30);
  std::cout << "   После вставки в t4. Его размер: " << t4.size()
            << ", размер оригинального t3: " << t3.size() << std::endl;
}
}  // namespace

void lab1::test::treap(int argc, char** argv) {
  if (argc < 1) {
    throw std::invalid_argument("Not enougth CLI arguments");
  }
  if (std::strcmp(argv[0], "ru") == 0) {
    demonstrate_treap_ru();
  } else {
    demonstrate_treap();
  }
}
