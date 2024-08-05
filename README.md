<div align="center">

  ![Untitled_Artwork_5](https://github.com/user-attachments/assets/1058bb02-42a4-4fb4-b89d-3f9a77f022d5)
 

</div>

---

# philosophers
The philosophers project is a simulation of the classic Dining Philosophers Problem, developed as part of the 42 Network curriculum. This project is designed to demonstrate the challenges and solutions involved in concurrent programming and synchronization.

--- 

# Features

- Simulation of multiple philosophers dining at a table
- Implementation of various synchronization techniques
- Handling of deadlocks and resource contention
- Visualization of philosopher states and actions

---

# Usage

### To run the simulation:

## Execute the program with the required arguments:

<pre>
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
</pre>

- [number_of_philosophers] - The number of philosophers (and forks) at the table.
- [time_to_die] - The time (in milliseconds) before a philosopher dies from starvation.
- [time_to_eat] - The time (in milliseconds) required for a philosopher to eat.
- [time_to_sleep] - The time (in milliseconds) a philosopher spends sleeping.
- [number_of_times_each_philosopher_must_eat] - The number of times each philosopher must eat before the simulation ends (set to -1 for infinite).

### Example:
<pre>
./philosophers 5 800 200 200 3
</pre>

- This command starts a simulation with 5 philosophers where each philosopher must eat 3 times, with times to die, eat, and sleep specified in milliseconds.

---

# How It Works

### The simulation models philosophers as threads, each with the following behaviors:

- Think: Philosophers think when they are not eating.
- Eat: Philosophers pick up the forks (resources) to eat and then release them.
- Sleep: Philosophers sleep after eating before starting the cycle again.

### Key features include:

- Mutexes: Used to synchronize access to forks and prevent deadlocks.
- Condition Variables: Manage philosopher states and transitions.
