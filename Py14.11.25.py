def greedy_scheduling(jobs, machines_count):
    machine_times = [0] * machines_count
    schedule = [[] for _ in range(machines_count)]
    
    sorted_jobs = sorted([(duration, i) for i, duration in enumerate(jobs)], reverse=True)
    
    for duration, job_index in sorted_jobs:
        min_machine = min(range(machines_count), key=lambda i: machine_times[i])
        
        schedule[min_machine].append((job_index, duration))
        machine_times[min_machine] += duration
    
    return schedule, machine_times

# Входные данные
machines = 3
jobs = [5, 7, 3, 8, 2, 6, 4, 9, 1, 5]

schedule, completion_times = greedy_scheduling(jobs, machines)

print("Длительности работ:", jobs)
print("Количество машин:", machines)
print("\nРасписание:")
for i, machine_jobs in enumerate(schedule):
    print(f"Машина {i+1}: {machine_jobs} (время завершения: {completion_times[i]})")

print(f"\nМаксимальное время завершения (makespan): {max(completion_times)}")

Вывод из консоли GDB:
Длительности работ: [5, 7, 3, 8, 2, 6, 4, 9, 1, 5]
Количество машин: 3

Расписание:
Машина 1: [(7, 9), (0, 5), (4, 2), (8, 1)] (время завершения: 17)
Машина 2: [(3, 8), (9, 5), (6, 4)] (время завершения: 17)
Машина 3: [(1, 7), (5, 6), (2, 3)] (время �авершения: 16)

Максимальное время завершения (makespan): 17
