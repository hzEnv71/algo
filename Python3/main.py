
# x+=78
def my_function():print("来自函数的你好")
my_function()
result = 16 / 4  # => 4.0 (Float Division)
print(result)
result = 16 // 4 # => 4 (Integer Division)
print(result)
result = 25 % 2  # => 1
print(result)
result = 5 ** 3  # => 125
print(result)
counter = 0
counter -= 10  
print(counter)
message = "Part 1."
# => Part 1.Part 2.
message += "Part 2." 
print(message)
print(f"Hello, {message}")
print(f'{counter} + 10 = {counter + 10}')
name = "Fred"
print(f"He said his name is {name!s}.")
mylist = []
mylist.append(1)
mylist.append(2)
for item in mylist:
    print(item) # 打印输出 1,2
age = 18       # 年龄是 int 类型
name = "John" +f"{age}" # 名字现在是 str 类型
print(name)
print(type(name),type(age))
list1 = ["apple", 23, "cherry"]
list2 = [True, False, False]
list3 = [1, 5, 7, 9, 3]
list4 = list((1, 5, "21", 9, 3))
print(list1,list4)
# 类似列表，但自身不可变
my_tuple1 = (1, "asda", 3)
my_tuple2 = tuple((1, 2, 'asd'))
print(my_tuple1,my_tuple2)
set1 = {"a", "a", "c"}   
set2 = set(("a", "b", 'b'))

print(set1,set2)
a = {"one": 1, "two": 2, "three": 3}
a.update({"four": 4})

print(a.keys(),a["one"],a.values(),a.get("one"))
hello = "Hello, World"
print(hello[1])  # 获取第二个字符
print(hello[-1])  # 获取倒数第一个字符
print(type(hello[-1]))  # 得到的还是字符串
for c in "foo":
    print(c,type(c),len(hello))
str,n="qwe",8
print(n*str)
s = 'spam'
print(s in 'I spamalot!',s not in 'ssas sp am ')
name = "John"
age = 23
print("%s is %d years old." % (name, age))
txt1 = "My name is {fname}, I'm {age}".format(fname="John", age=36)
txt2 = "My name is {1}, I'm {0}".format("John", 36)
txt3 = "My name is {}, I'm {}".format("John", 36)
print(txt1,txt2,txt3)
# name = input("Enter your name: ")
# print(name)
str="---".join(("sda", "asd", "asda"))
str="---".join({"a", "b", "c"})
str="---".join(["John", "Peter", "Vicky"])
print(str,type(str))
print("asd".count("a"),"asd".endswith("a"),"asd".startswith("a"),"as221".center(10))
for index in range(3, 8): 
    x = index * 10
    if index == 5:
        continue
    print(x)
x = 0
while x < 4:
    print(x)
    x += 1 
for i in range(4, 10, 2):
    print(i) # Prints: 4 6 8
name = ['Pete', 'John', 'Elizabeth']
age = [6, 23, 44]
for n, a in zip(name, age):
    print('%s is %d years old' %(n, a))
result = [x**2 for x in range(10) if x % 2 == 0]
print(result)
# kwargs 的类型是 dict
def keyword_args(**kwargs):
    return kwargs
print(keyword_args(big=3, asd="ness"))
# args 的类型是 tuple
def varargs(*args):
    return args
print(varargs(1, True, 3) )
print((lambda x: x > 2)(3),(lambda x, y: x ** 2 + y ** 2)(2, 1))
grid = [[1,2,4],[3,3,1]]
print(list(zip(*grid)))
print(sum(map(max,zip(*grid))))