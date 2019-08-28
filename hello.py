def foo(fun):
    print("i am foo")
    def inner(*args, **kwargs):
        print("111111")
        result = fun(*args, **kwargs)
        print("222222")
        return result
    return inner


def bar(fun):
    print("i am bar")
    def inner(*args, **kwargs):
        print("333333")
        result = fun(*args, **kwargs)
        print("444444")
        return result
    return inner

@foo
@bar
def fun():
    return "i am fun "


if __name__ == "__main__":
    print(fun())