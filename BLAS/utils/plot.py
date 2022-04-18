import matplotlib.pyplot as plt
import subprocess as sp
import pickle as pkl

RUNS = 5

def run_op(op : str, *args) -> dict:
    """
    Runs the given operation on the data.
    """
    # Run the operation
    process = sp.Popen(["bin/"+op, *args], stdout=sp.PIPE, stderr=sp.PIPE)
    stdout = process.communicate()

    # Parse the output
    output = stdout[0].decode("utf-8").split("\n")

    res = {}
    for line in output:
        if line == "":
            continue
        key, value = line.split(":")
        res[key.strip()] = float(value)

    return res

def benchmark(op : str, *args) -> dict:
    best = None
    for i in range(RUNS):
        res = run_op(op, *args)
        if not best or res["Runtime"] < best["Runtime"]:
            best = res

    return best

def plot(op : str) -> None:
    """
    Plots the results of benchmark
    """
    args = [100000, 500000, 1000000, 10000000, 100000000, 500000000]
    perf = []

    # with open("data/{}.pkl".format(op), "rb") as f:
    #     perf = pkl.load(f)
        

    for i in args:
        res = benchmark(op, str(i))
        perf.append(res)
        print(res)

    # plt.figure(figsize=(30, 10))

    # plt.subplot(1,3,1)
    plt.plot(args, [p["Runtime"] for p in perf], label="Runtime")
    plt.xlabel("Array Size")
    plt.ylabel("Runtime (s)")

    # plt.subplot(1,3,2)
    # plt.plot(args, [p["Flops"] for p in perf], label="GFlops")
    # plt.xlabel("Array Size")
    # plt.ylabel("Flops")

    # plt.subplot(1,3,3)
    # plt.plot(args, [p["Bandwidth"] for p in perf], label="Memory Bandwidth")
    # plt.xlabel("Array Size")
    # plt.ylabel("Bandwidth (GB/s)")

    # with open("data/"+op+".pkl", "wb") as f:
    #     pkl.dump(perf, f)

    plt.savefig("plots/"+op+".png")
    plt.clf()


if __name__ == "__main__":
    ...