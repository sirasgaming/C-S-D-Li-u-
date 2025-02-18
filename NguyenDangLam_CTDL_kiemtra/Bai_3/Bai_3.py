counter = {}
for sentence in open("Lamhihi.txt").read().split():

    if sentence in counter:
        counter[sentence] += 1
    else:
        counter[sentence] = 1
print(counter)
