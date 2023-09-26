#include <iostream>
using namespace std;

enum Codes { // Перечисление для работы меню.
	Работа, Выход
};
bool Work = Работа;

class List
{
private:
	struct Node
	{
		int data;
		Node* next;
	};
	Node* head;
public:
	List() // Конструктор
	{
		head = nullptr;
	}
	~List() { // Деструктор
		while (head != NULL) {
			DeleteFirstElement();
		}
	}

	int SearchLastListinList(List list) // Поиск последнего вхождения другого списка в список.
	{
		bool comparise = false;
		int LastIndex = 0;
		int CurrIndex = 0;
		bool NotEmpty = !list.CheckEmptyList();
		if (NotEmpty) {
			Node* current = head;
			while (current != NULL && current->next != NULL) {
				comparise = false;
				if (current->data == list.head->data) {
					comparise = true;
					Node* ListCurrent = list.head;
					while (current->next != nullptr && ListCurrent->next != nullptr && comparise)
					{
						current = current->next;
						CurrIndex++;
						ListCurrent = ListCurrent->next;
						if (ListCurrent->data != current->data)
						{
							comparise = false;
						}
					}
				}
				if (comparise)
				{
					LastIndex = CurrIndex;
				}
				CurrIndex++;
				current = current->next;
			}
		}
		if (NotEmpty) {
			return LastIndex;
		}
		else return 1;
	}

	int SearchFirstListinList(List list) // Поиск первого вхождения другого списка в список.
	{
		bool comparise = false;
		int FirstIndex = 0;
		int CurrIndex = 0;
		bool NotEmpty = !list.CheckEmptyList(); // Наш список пуст или не пуст
		if (NotEmpty) { // Если наш список не пустой
			Node* current = head; // Создаём текущий элемент, который равнется головному элементу первого списка.
			// Последовательное сравнение элементов исходного списка с головным элементом проверяемого списка.
			while (current != NULL && current->next != NULL) { // Если список этот элемент и последующий не равны 0.
				comparise = false;
				if (current->data == list.head->data) { // Если значение элементов совпали.
					// Если элементы совпали, то последовательно проверяются остальные элементы.
					comparise = true;
					Node* ListCurrent = list.head;
					while (current->next != NULL && ListCurrent->next != NULL && comparise) {
						current = current->next;
						ListCurrent = ListCurrent->next;
						if (ListCurrent->data != current->data) {
							comparise = false;
						}
					}
				}
				if (comparise) { // Если вхождение, то приравниваем индекс.
					FirstIndex = CurrIndex;
				}
				CurrIndex++; // Увеличиваем индекс.
				current = current->next; // Переход к следующему элементу.
			}
		}
		if (NotEmpty) {
			return FirstIndex;
		}
		else return -1;
	}
	bool CheckEmptyList() // Проверка на пустоту списка.
	{
		return head == NULL; // Если головной элемент ничему не равен, то список пуст.
	}
	int GetLengthList() // Получение размера списка.
	{
		int length = 0;
		if (!CheckEmptyList()) { // Если список непустой, то проходимся по всем его элементам и подсчитываем их.
			for (Node* current = head; current->next != NULL; current = current->next) {
				length++;
			}
			length++; // Прибавляем, так как отсчёт идет с 0 индекса.
		}
		return length;
	}
	int GetElementbyIndex(int index) // Получение элемента по индексу.
	{
		Node* current = head;
		if (GetLengthList() < index || index < 0) { // Проверка введённого индекса.
			cout << " Невозможно обработать этот индекс.\n";
		}
		else { // И если индекс удовлетворяет, то двигаемся до нужного индекса.
			for (int i = 0; i < index; i++) { // Подбираемся к нужному элементу.
				current = current->next;
			}
		}
		return current->data; // И возвращаем значение элемента.
	}
	void ReplacementTwoElements(List& list, int index1, int index2) // Обмен двух элементов списка по индексам.
	{
		if ((index1 >= 0 && index2 >= 0) && (list.GetLengthList() > index1 && (list.GetLengthList() > index2))) { // Проверка введённых индексов.
			int element;
			Node* current = head; // Создание узла.
			for (int i = 0; i < index1; i++) { // Подбираемся к нужному элементу.
				current = current->next;
			}
			Node* ListCurrent = list.head;
			for (int i = 0; i < index2; i++) {
				ListCurrent = ListCurrent->next;
			}
			element = current->data;
			current->data = ListCurrent->data;
			ListCurrent->data = element;
		}
		else {
			cout << "Невозможно обработать этот(~эти) индекс(-ы).";
		}
	}
	void Reverse() // Меняет порядок элементов в списке на обратный. 
	{
		int element;
		Node* current = head;
		for (int i = 0; i < GetLengthList(); i++) { // Проходим по списку, сдвигая элементы, кроме головного, влево на 1 элемент.
			current = head;
			element = current->data; // Запоминаем первый элемент.
			for (int j = 0; j < GetLengthList() - i - 1; j++) { // Двигаемся по всем элементам, кроме того, который запомнили.
				current->data = current->next->data;
				current = current->next;
			}
			current->data = element; // И последнему элементу приравниваем значение первого элемента.
		}
	}
	void ReplacementElementbyIndex(int data, int index) // Замена элемента по индексу на передаваемый элемент.
	{
		if (GetLengthList() < index || index < 0) {
			cout << " Невозможно обработать этот индекс.\n";
		}
		else {
			Node* current = head;
			for (int i = 0; i < index; i++) { // Доходим до нужного индекса.
				current = current->next;
			}
			current->data = data; // И меняем значение элемента.
		}
	}
	void DeleteAllElements() // Удаление всех элементов списка.
	{
		if (!CheckEmptyList()) {
			while (!CheckEmptyList()) { // Пока список не пустой, удалеям первый элемент.
				DeleteFirstElement();
			}
			cout << "Ваш  список пуст!";
		}
		else {
			cout << "Удаление не произошло, так как список пустой.\n";
		}
	}
	void DeleteElementbyIndex(int index) // Удаление элемента по индексу.
	{
		if (GetLengthList() < index || index < 0) {
			cout << " Невозможно обработать этот индекс.\n";
		}
		else if (!CheckEmptyList()) { // Если список непустой, то идём дальше.
			if (index == 0) { // Если элемент первый.
				DeleteFirstElement(); // Удаление первого элемента.
			}
			else {
				if (GetLengthList() - 1 == index) { // Если элемент последний.
					DeleteLastElement(); // Удаление последнего элемента.
				}
				else { // Если не первый и не последний.
					Node* current = head;
					for (int i = 0; i < index - 1; i++) { // Идём до нужного индекса.
						current = current->next;
					}
					Node* deleteNode = current->next; // Перезначаем связи и удаляем элемент.
					current->next = deleteNode->next;
					delete deleteNode;
				}
			}
		}
		else {
			cout << "Удаление не произошло, так как список пустой.\n";
		}
	}
	void DeleteFirstElement() // Удаление первого элемента.
	{
		if (!CheckEmptyList()) {
			Node* deleteNode = head; // Перезначаем связь и удаляем элемент.
			head = deleteNode->next;
			delete deleteNode;
		}
		else {
			cout << "Удаление не произошло, так как список пустой.\n";
		}
	}
	void DeleteLastElement() // Удаление последенего элемента.
	{
		if (!CheckEmptyList()) {
			Node* current = head;
			while ((current->next)->next != nullptr) { // Доходим до предпоследнего элемента в списке.
				current = current->next; // Находим последний элемент в списке.
			}
			Node* deleteNode = current->next;
			current->next = nullptr; // Перезначаем связь и удаляем элемент.
			delete deleteNode;
		}
		else {
			cout << "Удаление не произошло, так как список пустой.\n";
		}
	}
	void AddListEnd(List& list) //  Вставка списка в конец другого списка. 
	{
		if (!list.CheckEmptyList()) {
			Node* ListCur = list.head;
			for (int i = 0; i < list.GetLengthList(); i++) {
				this->AddEnd(ListCur->data);
				ListCur = ListCur->next;
			}
		}
		else cout << "Добавлять нечего, так как список пуст.\n";
	}
	void AddListFirst(List& list)  // Вставка списка в начало другого списка. 
	{
		if (!list.CheckEmptyList()) {
			Node* ListCur = list.head;
			for (int i = 0; i < list.GetLengthList(); i++) {
				this->AddElementbyIndex(ListCur->data, i);
				ListCur = ListCur->next;
			}
		}
	}
	void AddListbyIndex(List& list, int index) // Вставка другого списка в список, начиная с индекса. 
	{
		if (!list.CheckEmptyList()) {
			int length = GetLengthList();
			if (index >= 0 && length >= index) {
				if (index == 0) {
					AddListFirst(list);
				}
				else {
					if (index == length) {
						AddListEnd(list);
					}
					else {
						Node* current = head; // Элемент, после которого будет список.
						for (int i = 0; i < index-1; i++) {
							current = current->next;
						}
						Node* ListCurrent = list.head; // Последний элемент присоединяемого списка.
						while (ListCurrent->next != NULL) {
							ListCurrent = ListCurrent->next;
						}
						ListCurrent->next = current->next;
						current->next = list.head;
					}
				}
			}
			else {
				cout << "Нельзя обработать этот индекс.\n";
			}
		}
	}
	bool ComparisonList(List& list) { // Проверка на содержание другого списка в списке. 
		bool comparison = false;
		bool NotEmpty = !list.CheckEmptyList();
		if (NotEmpty) {
			Node* current = head;
			while (current != NULL && current->next != NULL) {
				comparison = false;
				if (current->data == list.head->data) {
					comparison = true;
					Node* ListCur = list.head;
					while (current->next != NULL && ListCur->next != NULL && comparison) {
						current = current->next;
						ListCur = ListCur->next;
						if (ListCur->data != current->data) {
							comparison = false;
						}
					}
				}
				current = current->next;
			}
		}
		if (NotEmpty) {
			return comparison;
		}
		else return 0;
	}
	void AddElementbyIndex(int data, int index) // Добавление элемента по индексу.
	{
		if (GetLengthList() >= index && index >= 0) {
			if (index == 0) {
				AddFirst(data);
			}
			else {
				if (index == GetLengthList()) {
					AddEnd(data);
				}
				else {
					Node* newNode = new Node;
					newNode->data = data;
					Node* curr = head;
					for (int i = 0; i < index - 1; i++) {
						curr = curr->next;
					}
					newNode->next = curr->next;
					curr->next = newNode;
				}
			}
		}
		else {
			cout << " Невозможно обработать этот индекс.\n";
		}
	}
	void AddFirst(int data) // Добавление элемента в начало списка.
	{
		Node* node = new Node;
		node->data = data;
		if (head == nullptr)
		{
			node->next = nullptr;
			head = node;
		}
		else
		{
			node->next = head;
			head = node;
		}
	}
	void AddEnd(int data) // Добавление элемента в конец списка.
	{
		Node* node = new Node;
		node->data = data;
		node->next = nullptr;
		if (head == nullptr)
		{
			node->next = nullptr;
			head = node;
		}
		else
		{
			Node* current = head;

			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = node;

		}
	}
	void Output() // Вывод элементов списка.
	{
		cout << "Ваш список: ";
		for (Node* current = head; current != nullptr; current = current->next) {
			cout << current->data << ' ';
		}
		cout << "\n";
	}
};

void CheckEmpty(List* list) { // Проверка на пустоту списка и вывод информации.
	bool check;
	check = list->CheckEmptyList(); // Получаем true или false в звисимости от того, равен ли первый элемент NULL.
	if (check) { // Если равно true, то пустой, иначе что-то есть.
		cout << "Ваш список пуст.\n";
	}
	else cout << "Ваш список не пуст.\n";
}

void Insertion_AddEnd(List* list) { // Ввод элемента для вставки в конец, сама вставка и вывод списка.
	int index, element;
	cout << "Введите элемент, который хотите добавить:\n";
	cin >> element;
	list->AddEnd(element); // Функция для вствки в конец списка.
	list->Output(); // Вывод списка.
}
void Insertion_AddFirst(List* list) { // Ввод элемента для вставки в начало, сама вставка и вывод списка. 
	int element;
	cout << "Введите элемент, который хотите добавить: \n";
	cin >> element;
	list->AddFirst(element); // Функция для вставки элемента в начало списка.
	list->Output(); // Вывод списка.
}

void Add_Insert(List* list1, List* list2) { // Методы вставки и добавления элемента.
	cout << "\nКакой именно метод вы хотите рассмотреть?\n";
	cout << "1.Добавление в конец списка.\n" // Insertion - AddEnd(int element)
		<< "2.Добавление в начало списка.\n" // Insertion - AddFirst(int element)
		<< "3.Добавление элемента по индексу (вставка перед элементом, который был ранее доступен по этому индексу).\n"
		<< "4.Вставка другого списка в список, начиная с индекса.\n"
		<< "5.Вставка другого списка в конец.\n"
		<< "6.Вставка другого списка в начало.\n"
		<< "7.Вернуться в меню.\n";
	int choice;
	cin >> choice;
	switch (choice) { // Выбор нужного метода.
	case 1:
		Insertion_AddEnd(list1);
		break;
	case 2:
		Insertion_AddFirst(list1);
		break;
	case 3:
		int element, index;
		cout << "Введите элемент, который хотите добавить: \n";
		cin >> element;
		cout << "Введите индекс, куда необходимо вставить элемент: \n";
		cin >> index;
		list1->AddElementbyIndex(element, index);
		list1->Output();
		break;
	case 4:
		cout << "Введите индекс, после которого требуется вставить второй список в первый: ";
		cin >> index;
		cout << endl;
		list1->AddListbyIndex(*list2, index);
		list1->Output();
		break;
	case 5:
		list1->AddListEnd(*list2);
		list1->Output();
		break;
	case 6:
		list1->AddListFirst(*list2);
		list1->Output();
		break;
	case 7:
		break;
	default:
		cout << "Такого варианта нет.";
		break;
	}
}

void Delete_Replacement(List* list1, List* list2) {
	cout << "\nКакой именно метод вы хотите рассмотреть?\n";
	cout << "1.Удаление последнего элемента.\n"
		<< "2.Удаление первого элемента.\n"
		<< "3.Удаление элемента по индексу.\n"
		<< "4.Удаление всех элементов списка.\n"
		<< "5.Замена элемента по индексу на передаваемый элемент.\n"
		<< "6.Меняет порядок элементов в списке на обратный.\n"
		<< "7.Обмен двух элементов списка по индексам.\n"
		<< "8.Вернуться в меню.\n";
	int choice;
	cin >> choice;
	switch (choice) { // Выбор нужного метода.
	case 1:
		list1->DeleteLastElement();
		list1->Output();
		break;
	case 2:
		list1->DeleteFirstElement();
		list1->Output();
		break;
	case 3:
		int index;
		cout << "Введите индекс, элемент которого необходимо удалить: \n";
		cin >> index;
		list1->DeleteElementbyIndex(index);
		list1->Output();
		break;
	case 4:
		list1->DeleteAllElements();
		break;
	case 5:
		int element;
		cout << "Введите индекс элемента, который хотите заменить:\n";
		cin >> index;
		cout << "На какой элемент заменить?\n";
		cin >> element;
		list1->ReplacementElementbyIndex(element, index);
		list1->Output();
		break;
	case 6:
		list1->Reverse();
		list1->Output();
		break;
	case 7:
		cout << "Список до замены: \n";
		list1->Output();
		int indexFirst, indexSecond;
		cout << "Введите первый индекс: ";
		cin >> indexFirst;
		cout << "\nВведите второй индекс: ";
		cin >> indexSecond;
		cout << endl << "Список после замены: \n";
		list1->ReplacementTwoElements(*list1, indexFirst, indexSecond);
		list1->Output();
		break;
	case 8:
		break;
	default:
		cout << "Такого варианта нет.";
		break;
	}
}
void OtherMethods(List* list1, List* list2) {
	cout << "\nКакой именно метод вы хотите рассмотреть?\n";
	cout << "1.Получение элемента по индексу.\n"
		<< "2.Получение размера списка.\n"
		<< "3.Проверка на пустоту списка.\n"
		<< "4.Поиск первого вхождения (первый индекс) другого списка в список.\n"
		<< "5.Поиск последнего вхождения (последний индекс) другого списка в список.\n"
		<< "6.Проверка на содержание другого списка в списке.\n"
		<< "7.Вернуться в меню.\n";
	int choice;
	cin >> choice;
	switch (choice) { // Выбор нужного метода.
	case 1:
		int index, element;
		cout << "Введите индекс, чтобы узнать значение элемента: ";
		cin >> index;
		cout << "На [" << index << "] стоит: " << list1->GetElementbyIndex(index) << endl;
		break;
	case 2:
		cout << "Длина вашего списка: " << list1->GetLengthList() << endl;
		break;
	case 3:
		CheckEmpty(list1);
		break;
	case 4:
		cout << "Первое вхождение другого списка в список: " << list1->SearchFirstListinList(*list2);
		break;
	case 5:
		cout << "Последнее вхождение другого списка в список: " << list1->SearchLastListinList(*list2);
		break;
	case 6:
		bool check;
		list1->ComparisonList(*list2);
		check = list1->ComparisonList(*list2); // Получаем true или false в звисимости от того, есть ли элементы или нет.
		if (check) {
			cout << "Один список содержится в другом.\n";
		}
		else cout << "Один список НЕ содержится в другом.\n";
		break;
	case 7:
		break;
	default:
		cout << "Такого варианта нет.";
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	List* list = new List;
	List* secondlist = new List;

	// Цифры введены для того, чтобы первый список изначально не был пустым, это можно удалить, можно поменять и т.д.

	//for (int i = 0; i < 100; i++) {
	list->AddEnd(4);
	list->AddEnd(56);
	list->AddEnd(345);
	list->AddEnd(100);
	list->AddEnd(56);
	list->AddEnd(90);
	list->AddEnd(15);	
	list->AddEnd(58);
	list->AddEnd(32);
	list->AddEnd(100);
	//}


	//for (int i = 0; i < 100; i++) {
	secondlist->AddEnd(100);
	secondlist->AddEnd(56);
	secondlist->AddEnd(90);
	//}

	int choice;
	cout << "1) ";
	list->Output();
	cout << "2) ";
	secondlist->Output();

	while (Work == Работа) { // Консольное меню.
		cout << endl;
		cout << "Выберите необходимый метод: \n";
		cout << "1. Добавление/Вставка элемента(-ов).\n"
			<< "2. Удаление/Замена элемент(-ов).\n"
			<< "3. Другие методы.\n"
			<< "4. Завершение программы.\n";
		cin >> choice;
		switch (choice) {
		case 1:
			Add_Insert(list, secondlist); // Методы добавления и вставки элементов.
			break;
		case 2:
			Delete_Replacement(list, secondlist); // Методы удаления и замены элементов.
			break;
		case 3:
			OtherMethods(list, secondlist); // Другие методы.
			break;
		case 4:
			Work = Выход;
			break; // Завершение программы.
		default:
			cout << "Введите существующий вариант."; // Сообщение об ошибке.
		}
	}
}


