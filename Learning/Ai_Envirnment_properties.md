# AI Environment Properties — Quick Revision Notes

When describing an AI environment, we can classify it using **six properties**.

---

## 1. Observable

### Fully Observable

The agent can obtain all relevant information about the current state of the environment.

**Example:** Chess — the board and pieces are visible.

### Partially Observable

Some relevant information is hidden, unavailable, or cannot be sensed.

**Example:** Self-driving car in fog — it cannot clearly see everything around it.

**Remember:**

> Fully = enough relevant information is available.
> Partially = some relevant information is missing.

---

## 2. Deterministic vs Stochastic

### Deterministic

The same action in the same situation gives a predictable result.

**Example:** A calculator or a chess move.

### Stochastic

The result is uncertain; an action can lead to different possible outcomes.

**Example:** Driving in traffic — other drivers may suddenly change direction.

**Remember:**

> Deterministic = predictable outcome.
> Stochastic = uncertain outcome.

---

## 3. Episodic vs Sequential

### Episodic

Each decision/task is independent. Previous decisions do not affect the next one.

**Example:** Classifying individual emails as spam/not spam.

### Sequential

Previous actions or states affect future decisions.

**Example:** Chess — every move changes the board for the next move.

**Remember:**

> Episodic = each task is separate.
> Sequential = decisions are connected over time.

---

## 4. Static vs Dynamic

### Static

The environment does not change by itself while the agent is deciding.

**Example:** Sudoku.

### Dynamic

The environment can change while the agent is deciding or operating.

**Example:** A racing game — other cars keep moving while the AI is making decisions.

**Remember:**

> Static = the world waits.
> Dynamic = the world keeps moving.

---

## 5. Discrete vs Continuous

### Discrete

States or actions have separate/countable possibilities.

**Example:** Chess moves.

### Continuous

Values can change smoothly across a range.

**Example:** Car speed, position, steering angle.

**Remember:**

> Discrete = separate values.
> Continuous = smoothly varying values.

---

## 6. Single-Agent vs Multi-Agent

### Single-Agent

Only one agent is making decisions in the environment.

**Example:** A robot vacuum cleaning an empty room.

### Multi-Agent

Multiple agents are making decisions and interacting with each other.

**Example:** Chess or an online racing game.

**Remember:**

> Single = one decision-making agent.
> Multi = multiple decision-making agents.

---

# Example: Self-Driving Car

A simplified self-driving environment can be:

* **Partially observable** → cannot see everything.
* **Stochastic** → other road users may behave unpredictably.
* **Sequential** → previous actions affect future state.
* **Dynamic** → traffic keeps moving.
* **Continuous** → speed, position and steering vary continuously.
* **Multi-agent** → other drivers/agents are present.

---

# Six Questions to Remember

When you see an AI environment, ask:

1. **Can the agent see all relevant information?**
   → Observable

2. **Can the result of an action be predicted exactly?**
   → Deterministic / Stochastic

3. **Do previous decisions affect future decisions?**
   → Episodic / Sequential

4. **Does the world change while the agent is thinking?**
   → Static / Dynamic

5. **Are states/actions separate or smoothly varying?**
   → Discrete / Continuous

6. **How many decision-making agents are there?**
   → Single / Multi-agent
