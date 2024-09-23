# Informative Speech

## Introduction  (1 - 1:30)

### Attention Getter

Lets think about everything that needs to go into setting up a scientific experiment. You need to have an environment that minimizes external influences, tools to collect data, and most importantly the subject of the experiment itself. But for some applications setting up all of this infrastructure is just not feasible. 

### Audience Relevance

You might not realize it, but a large portion of science that influences our every day lives is done with simulation on supercomputers. From predicting the weather, to understanding how medicine affects the body, to designing new energy technology, simulation is a essential resource to scientists around the world according to Alan Turing Institute. 

https://www.turing.ac.uk/research/interest-groups/simulation-based-science#:~:text=Simulation%20has%20become%20a%20cornerstone,the%20movement%20of%20individual%20cells.

### Credibility

When I started at Clemson, I was immersed in the field of scientific computing through a creative inquiry, which involved building a mini supercomputer and competing in an international supercomputing competiton. I ended up loving it and going on to do research in supercomputing both at Clemson, and at Los Alamos National Lab which is one of the most advanced scientific research centers in the world. These experiences have given me a detailed view of how supercomputers work, and how they are used to advance science.

### Thesis

Scientists rely on supercomputers to simulate experiments, but these systems are extremely complex to design and maintain. 

### Topical Outline Sentence

Going to talk about what supercomputers are, and how they are used to perform simulations.

## Main Point 1: Supercomputers (3 - 4 min)

So, what are supercomputers? At a high level, they are just really big computers like the name implies. They are so big in fact, that the biggest supercomputers are a million times more powerful than an ordinary desktop or laptop computer. They can do over a quintillion calculations per second, as opposed to desktop computers mere trillion. 

https://www.science.org/content/article/world-s-fastest-supercomputers-are-helping-sharpen-climate-forecasts-and-design-new#:~:text=Completed%20in%20May%202022%2C%20Frontier,than%20an%20average%20desktop%20computer.

How do you achieve this insane performance? Well, the most effective method is to take a bunch of these desktop processors and allow programs to be broken apart and have different parts of the program executing on all of the processors in parallel at the same time. We call the individual computers within the supercomputer nodes. Think of it like a big beehive of collaborating computers. The supercomputer consists of thousands of high powered compute nodes that are connected together with advanced network technology so the different components of the parallel program can run at the same time and communicate with each other during execution. Supercomputers also contain a super scale filesystem to store all the data they generate.

First, lets talk about the supporting infrastructure that supercomputers require. These supercomputers live in data centers, which are essentially massive warehouses that contain rows and rows of computers. This image shows the installation of one of the latest supercomputers at Los Alamos data center, which is about the size of a football field and is stuffed to the brim with supercomputers. 

https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.datacenterdynamics.com%2Fen%2Fnews%2Flos-alamos-national-laboratory-installs-first-phase-of-crossroads-supercomputer%2F&psig=AOvVaw2_fp7QsHuGNms9Mx58s3o8&ust=1708916689003000&source=images&cd=vfe&opi=89978449&ved=0CBUQjhxqFwoTCKjWyNjAxYQDFQAAAAAdAAAAABAR

If you look closely, you can see the individual nodes. Up top, you can see the huge liquid cooling pipes, because if you think your laptop gets hot, imagine how much heat these supercomputers produce. Fun fact according to some of the data center engineers, the main liquid cooling pipe for the Los Alamos data center is three feet across. Another interesting variable is power. The Los Alamos data center currently uses around 40 Megawatts of power, and will soon be upgraded to use 60 according to one of the division leaders. For reference, that is more power than the entire town of 13000 people. 

Now, lets talk more about how supercomputers are structured. Like I have mentioned, and can be seen in this diagram, a supercomputer is a cluster of computers connected over a high speed network. The red boxes here represent the nodes and blue box represents a hub for the network. Network hubs are used so that each node does not have to have a direct connection to every other node, it can just have one connection to the hub, and communicate with every other device connected to that hub. However, this network is not your typical Ethernet or Wifi. It is a network technology called Infiniband that is designed specifically for the purpose of allowing computers to share information when running parallel programs. 

The last component shown in the diagram is a parallel filesystem, which handles the large amounts of data generated by supercomputers. The parallel filesystem applies the exact same concept as parallel processing: splitting up a large amount of data across individual hard drives. The scientists from the paper below generated a model of the entire universe on a supercomputer in Japan, which takes up 3000 Terabytes, or 3 Petabytes of space. This is so big that a parallel filesystem would be required to store it, and would essentially break apart the data into 1 TB chunks and store each chunk on a separate a hard drive in the aggregate system. 

https://arxiv.org/abs/2007.14720

Now that you understand how supercomputers work at a high level, lets look an example that is related to simulation. 

## Main Point 2: Simulation (1 - 2 min)

Here is a map of the US, and lets say that we want to predict the temperatures for the upcoming week. The US is a big place, and there are a lot of different weather patterns occuring at any given time. To simulate this on a standard desktop computer would takes months or even years depending on precision, and by that time, your forecast would not be very helpful. We need to use a supercomputer.

This is a gross oversimplification of what is actually done to simulate climate, but lets break apart our map into 8 regions, regions and process each one in parallel on nodes in the supercomputer. Now the simulation will ideally run 8 times faster. In reality, there is overhead from nodes having to share data over the network do to things like, ensuring border values are accurate, and recombining the results from each subregion into a single unit at the end, so you will never get the theoretical 8 times speed up, but still far better than running everything serially on a single computer. This idea can be scaled up to break the map apart into thousands of regions and run all of those in parallel for optimal speed up. 

Once the simulation completes and we have our data, we need a place to store it. The data will likely be large enough that a parallel filesystem is needed, and to store the data, we use a similar approach to the computation and break it apart into chunks, and store each chunk on an individual hard drive. 


## Conclusion (30 sec)

Supercomputers provide the necessary simulation power for many disciplines of science to execute their experiments and forecasts. In this talk, we discussed how supercomputers consist of compute nodes, a high speed network, and a parallel filesystem, and how each of these components is used when running a real world simulation. I hope you feel like you have learned something, and that is all I have. 



