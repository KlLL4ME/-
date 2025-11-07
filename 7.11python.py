def generate_binary_strings(n, current=""):
    # Базовый случай: строка достигла длины n
    if len(current) == n:
        print(current)
        return

    # Рекурсивный случай: добавляем '0' или '1' и продолжаем
    generate_binary_strings(n, current + "0")
    generate_binary_strings(n, current + "1")

# Тестирование
n = 3
print(f"Все бинарные строки длины {n}:")
generate_binary_strings(n)
