#include <iostream>
#include <string>
#include <memory>

template<typename T>
class Printer {
public:
	virtual void print(T& data);
};

template<typename T>
class ConsolePrinter : public Printer<T> {
public:
	void print(T& data) {
		std::cout << data << std::endl;
	}
};

template<typename T>
class PrintInvoker {
private:
	Printer<T> * m_printer;
public:
	explicit PrintInvoker(Printer<T> * printer) {
		this->m_printer = printer;
	}

	~PrintInvoker() {
		delete this->m_printer;
	}

	void invoke(T& data) {
		this->m_printer->print(data);
	}
};


class Fibbonacci {
private:
	PrintInvoker<int> * m_invoker;
public:
	explicit Fibbonacci(PrintInvoker<int> * invoker) {
		this->m_invoker = invoker;
	}

	~Fibbonacci() {
		delete m_invoker;
	}

	int fib(int n) {
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return 1;
		}
		return fib(n - 1) + fib(n - 2);
	}
};



void fib(int n, PrintInvoker<int> * invoker);

int main() {

	ConsolePrinter<int> * intPrinter = new ConsolePrinter<int>();
	PrintInvoker<int> * invoker = new PrintInvoker<int>(intPrinter);


	fib(10, invoker);

	fib(20, invoker);


	return 0;
}

void fib(int n, PrintInvoker<int> * invoker) {
	Fibbonacci fib(invoker);
	fib.fib(10);
}