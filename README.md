<!-- PROJECT START -->
# Fibonacci heap
Implementing a Fibonacci heap to find the shortest path for a provided set of a graph's edges and vertices.

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#help">Help</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About the project

In a weighted, undirected graph *the shortest path problem* is the problem of finding the shortest path connecting one vertex (the start vertex)
to another vertex (the destination vertex).

To solve this problem, a Fibonacci heap can be used to implement a minimum priority queue that offers an efficient decrease key operation. By 
following the chain of predecessor pointers backwards from a destination to the source, we will be able to construct the shortest path from the 
source to the destination.

The objective of this program is to use a Fibonacci heap in order to use find the shortest path of a provided graph.

<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

Things you need to use the software.
* MacOS
* Xcode

### Installation

Clone this repo.
   ```sh
   git clone https://github.com/vmthanh-bi/Fibonacci-heap.git
   ```

<!-- Help -->
## Help

See the [open issues](https://github.com/vmthanh-bi/Fibonacci-heap/issues) for a list of proposed features (and known issues).

<!-- CONTACT -->
## Contact

Tony Vu - [@vmthanh.bi](https://github.com/vmthanh-bi) - vmthanh.bi@gmail.com

Project Link: [https://github.com/vmthanh-bi/Prim-s-Algorithm](https://github.com/vmthanh-bi/Prim-s-Algorithm)

<!-- MARKDOWN LINKS & IMAGES -->

