class MyClass {
public:
    MyClass() { /* constructor */ }
    ~MyClass() { /* destructor */ }
};

int main() {
    MyClass* obj = new MyClass();  // 创建一个MyClass对象
    MyClass &anotherObj = *obj;     // 将指针解引用，赋值给anotherObj
    // 此时，anotherObj是obj指针所指对象的副本             // 手动释放obj所指的内存
    return 0;
}