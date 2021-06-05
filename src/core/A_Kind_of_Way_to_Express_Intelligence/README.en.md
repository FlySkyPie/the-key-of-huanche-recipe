# A Kind of Way to Express Intelligence

## The Nature Of Intelligence
> What is intelligence?

That's the question which many people working on artificial intelligence would asked. Let standing at the basic of natural science to look this question.

### Thermodynamic arrow of time
The arrow of time is the "one-way direction" or "asymmetry" of time. The thermodynamic arrow of time is provided by the second law of thermodynamics, which says that in an isolated system, entropy tends to increase with time. Entropy can be thought of as a measure of microscopic disorder; thus the second law implies that time is asymmetrical with respect to the amount of order in an isolated system: as a system advances through time, it becomes more statistically disordered. This asymmetry can be used empirically to distinguish between future and past, though measuring entropy does not accurately measure time. [^thermodynamic-arrow-of-time] So there for would be consequent between past and future, "cause" and "effect" .

### Mapping Relationship Between Cause And Effect
The relationship between cause and effect can be written by boolean function as below:
$$
C \in \Bbb B \\
E \in \Bbb B \\
C^{n} \to E \\
\text{or} \\
E(c_1, c_2, c_3...., c_n)
$$

### Intelligence of creatures
The intelligent creatures just a logical system to make reaction with environment information, which the nature of intelligent is a mapping relationship, the informations from environment are cause and the reactions of creature made are effect. So we can express intelligence of creatures by boolean function but huge and complicate.

## Neural Network
It's undeniable that artificial neural network had flexibility which creating many kind of logical mapping relationship, but the artificial neural network that based floating point arithmetic cause many information losing, computer cost too many time and energy to calculating the information that we don't needed.

Of course there are information also loses in boolean calculation, but it necessary process which extracting value information for agents, and unliked artificial neural network, boolean algebra had more interpretability, we can translate relation between input and output.

There for, why not to use both of artificial neural network and boolean algebra? This is a formula of neuron of artificial neural network:
$$
y=\sum^{n}_{i=1} x_i w_i + b
$$

and its formula of neuron of BNN (boolean neural network):
$$
y =   \underset{i}{\overset{n}{ \land }} (x_i \oplus w_i)
$$

### Why Don't Just Using Logic Array?
Because BNN have some properties which logic array don't had:
Logic array cannot contain recurrent structure (memory unit). But major problem is interpretability, as know as the hidden layers in the artificial neural network can be explained as extracting features and provided more specific concepts, there for logic array cannot provided tree structure to do that.

### General Logic Unit
Just like biology, we observe subjects and make inductive science system to study them.
There might reasonably be expected from some patterns of BNN occurred repeatedly and been observed, that means those patterns are GLU (generic logic unit). When we had created knowledge base of GLU, would allow us to explanation how BNN "thinking".

[^thermodynamic-arrow-of-time]: Arrow of time - Wikipedia. (n.d.). Retrieved 2020-03-13, from https://en.wikipedia.org/wiki/Arrow_of_time

###### tags: `The Key Of Huanche`
