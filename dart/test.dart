anyUserUnder18(int age) => age <= 17;
everyUserOver13(int age) => age >= 14;

void main() {
  ex_2();
}

void ex_1() {
  var items = ["hello", "world", "Make"];
  // print(col.singleWhere((age) => age <= 17));
  try {
    print(items.singleWhere((item) => item.contains('a') && item[0] == 'M'));
  } catch (e) {
    print("no text start with 'M' and contain 'a'");
  }
}

void ex_2() {
  var users = [9, 11, 13, 16, 17, 21, 35];
  print(users.any((age) => age <= 17));
  print(users.every((age) => age >= 14));
}

void ex_3() {
  
}