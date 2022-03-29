# Software Programming for Performance
>  **Name : Abhijnan Vegi**  
>  **Roll No : 2020101004**  
>  **Assignment 1**


## Know your Computer
### CPU Specifications

|      Specification       |         Value         |
| :----------------------: | :-------------------: |
|           CPU            |      AMD Ryzen 7      |
|          Model           |         4800H         |
|     Frequency Range      |    2.9GHz - 4.2GHz    |
| Number of physical cores |           8           |
|      Hyperthreading      |          Yes          |
|         SIMD ISA         |         AVX2          |
|          Cache           | 512 KiB, 4 MiB, 8 MiB |
|     Memory Bandwidth     |      68.27 GB/s       |


#### Theoretical FLOPS
#### Whetstone benchmark
Running the whetstone benchmark with 10^6^ loops gives a total of 6.25 GFLOPS.
```
Loops: 1000000, Iterations: 1, Duration: 16 sec.
C Converted Double Precision Whetstones: 6250.0 MIPS
```
Compiling the whetstone benchmark with the flag `-O3` we get the following result
```
Loops: 1000000, Iterations: 1, Duration: 4 sec.
C Converted Double Precision Whetstones: 25000.0 MIPS
```
Using the `icc` compiler instead of `gcc` gives us 10 GFLOPS even with the `-O3` flag
#### My benchmark

### Memory Specifications

|      Specification       |   Value    |
| :----------------------: | :--------: |
|       Memory size        |   32 GiB   |
|           Type           |    DDR4    |
| Maximum Memory Bandwidth | 34.13 GB/s |

### Storage Specifications

1. **SSD**

   | Specification |  Value  |
   | :-----------: | :-----: |
   |     Size      | 256 GiB |
   |     Read      |         |
   |     Write     |         |

2. **HDD**

   | Specification | Value |
   | :-----------: | :---: |
   |     Size      | 1 TiB |
   |     Read      |       |
   |     Write     |       |


