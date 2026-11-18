def activity_selection(activities):
    n = len(activities)

    # Sort activities by finishing time using Bubble Sort
    for i in range(n - 1):
        for j in range(n - i - 1):
            if activities[j][1] > activities[j + 1][1]:
                activities[j], activities[j + 1] = activities[j + 1], activities[j]

    selected = []

    if n == 0:
        return selected

    selected.append(activities[0])
    last_finish = activities[0][1]

    for i in range(1, n):
        if activities[i][0] >= last_finish:
            selected.append(activities[i])
            last_finish = activities[i][1]

    return selected


n = int(input("Enter number of activities: "))
activities = []

for i in range(n):
    print("Enter start and finish time of activity", i + 1)
    start = int(input("Start: "))
    finish = int(input("Finish: "))
    activities.append((start, finish))

result = activity_selection(activities)

print("Selected activities:")
for activity in result:
    print(activity)

print("Maximum number of activities:", len(result))