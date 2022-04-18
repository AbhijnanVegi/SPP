import matplotlib.pyplot as plt
import subprocess as sp
import pickle as pkl

RUNS = 5

def run_op(op : str, *args) -> dict:
    """
    Runs the given operation on the data.
    """
    # Run the operation
    process = sp.Popen(["./" + op, *args], stdout=sp.PIPE, stderr=sp.PIPE)
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
    args = [3, 5 ,10 , 50 , 100]
    perf = []

        

    for i in args:
        res = benchmark(op, str(i))
        perf.append(res)
        print(res)


    plt.plot(args, [p["Runtime"] for p in perf], label="Runtime")
    plt.xlabel("Stencil Size")
    plt.ylabel("Runtime (s)")


    plt.savefig(op+".png")
    plt.clf()


if __name__ == "__main__":
    plot("stencil")