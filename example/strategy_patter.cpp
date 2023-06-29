#include <vector>

class Item {
 public:
  bool is_fresh() { return is_fresh_; }
  float price() { return price_; }

 private:
  bool is_fresh_ = false;
  float price_ = 0.0;
};

class DiscountStrategy {
 public:
  virtual float GetDiscountPrice(Item item) {}
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

DiscountStrategy strategy;

class Calculator {
 public:
  Calculator(DiscountStrategy strategy) : strategy_(strategy) {}
  float Calculate(
      std::vector<Item> items) {  // 계산하는 부분은 전략에 따라 변하지 않음
    float sum = 0.0;
    for (auto& item : items) {
      sum += strategy_.GetDiscountPrice(item);
    }
    return sum;
  }

 private:
  DiscountStrategy strategy_;
};

void PushFirstCustomerButtom() {  // 버튼 누를 때 전략 선택
  strategy = FirstCustomerDiscountStrategy();
};
void PushLastCustomerButton() {  // 버튼 누를 때 전략 선택
  strategy = LastCustomerDiscountStrategy();
};
void PushCalculationButton() {  // 실제 계산 실행 버튼
  Calculator calculator(strategy);
  std::vector<Item> items;
  float result = calculator.Calculate(items);
};

int main() { return 0; }
