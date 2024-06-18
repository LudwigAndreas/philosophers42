# Philosophers

This project is a simulation of the dining philosophers problem. The program creates a certain number of philosophers and forks. Each philosopher can be in one of three states: `eating`, `sleeping`, `thinking`. The philosopher can only eat if he has two forks. The program uses threads and mutexes to synchronize the philosophers' actions.

## Table of Contents

- [About](#about)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installing](#installing)
- [Running the tests](#running-the-tests)
- [Usage](#usage)
- [Built Using](#built-using)
- [Authors](#authors)
- [Acknowledgements](#acknowledgements)
- [License](#license)

## About

The dining philosophers problem is a classic synchronization problem. The problem consists of a table with five philosophers sitting around it. Each philosopher has a plate of spaghetti. A fork is placed between each pair of adjacent philosophers. A philosopher needs two forks to eat. The problem is how to design a discipline of behavior (a concurrent algorithm) such that each philosopher will not starve, i.e., each can eat forever often.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

What things you need to install the software and how to install them.

```text
gcc >= 7.5.0
make >= 4.1
```

```bash
sudo apt-get install make
sudo apt-get install gcc
```

### Installing

A step by step series of examples that tell you how to get a development env running.

Clone the repository.

```bash
git clone https://github.com/LudwigAndreas/philosophers42

cd philosophers42
```

Build the project.

```bash
make
```

or build with bonus.

```bash
make bonus
```

Run the project.

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

## Running the tests

Explain how to run the automated tests for this system.

```bash
make test
```

## Usage

After running the program, you will see how the philosophers are eating, sleeping, and thinking.

## Built Using

- [C](https://en.wikipedia.org/wiki/C_(programming_language)) - Programming language
- [Make](https://en.wikipedia.org/wiki/Make_(software)) - Build automation tool

## Authors

This project was developed by:

| <img src="https://avatars.githubusercontent.com/u/88089961?v=4" alt="drawing" width="50"/> |[LudwigAndreas](https://github.com/LudwigAndreas)|
| --- | --- |

## Acknowledgements

- [School 21](https://21-school.ru/) - Educational institution
- [42](https://www.42.fr/) - Educational institution

## License

This project is licensed under the School 21 License - see the [LICENSE](LICENSE) file for details.
