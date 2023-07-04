#include <iostream>
#include <vector>

class Item {
 public:
  Item(float price, bool is_fresh) : price_(price), is_fresh_(is_fresh){};

  bool is_fresh() { return is_fresh_; }
  float price() { return price_; }

 private:
  bool is_fresh_ = false;
  float price_ = 0.0;
};

class DiscountStrategy {
 public:
  virtual float GetDiscountPrice(
      Item item) = 0;  // 각 Strategy 로 overwrite 할 함수
};

class FirstCustomerDiscountStrategy : public DiscountStrategy {
 public:
  float GetDiscountPrice(Item item) {
    if (item.is_fresh()) {
      return item.price() * 0.9;
    } else {
      return item.price() * 0.9 * 0.7;
    }
  }
};
class LastCustomerDiscountStrategy : public DiscountStrategy {
 public:
  float GetDiscountPrice(Item item) {
    if (item.is_fresh()) {
      return item.price() * 0.8;
    } else {
      return item.price() * 0.8 * 0.7;
    }
  }
};

DiscountStrategy* strategy;  // 다형성(Polymorphism)은 pointer 일때 가능하다!

class Calculator {
 public:
  Calculator(DiscountStrategy* strategy) : strategy_(strategy) {}
  float Calculate(
      std::vector<Item> items) {  // 계산하는 부분은 전략에 따라 변하지 않음
    float sum = 0.0;
    for (auto& item : items) {
      sum += strategy_->GetDiscountPrice(item);
    }
    return sum;
  }

 private:
  DiscountStrategy* strategy_;
};

void PushFirstCustomerButtom() {  // 버튼 누를 때 전략 선택
  std::cout << "First Customer Button is pushed" << std::endl;
  strategy = new FirstCustomerDiscountStrategy();
};
void PushLastCustomerButton() {  // 버튼 누를 때 전략 선택
  std::cout << "Last Customer Button is pushed" << std::endl;
  strategy = new LastCustomerDiscountStrategy();
};
void PushCalculationButton() {  // 실제 계산 실행 버튼
  Calculator calculator(strategy);
  std::vector<Item> items;
  Item item1(100.0, false);
  Item item2(200.0, true);
  items.push_back(item1);
  items.push_back(item2);
  float result = calculator.Calculate(items);
  std::cout << "Calculated price is " << result << std::endl;
};

int main() {
  PushFirstCustomerButtom();
  PushCalculationButton();

  PushLastCustomerButton();
  PushCalculationButton();

  return 0;
}
