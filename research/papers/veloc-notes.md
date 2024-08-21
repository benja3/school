# VELOC Paper Notes

## Abstract

Storage systems becoming more heterogenous with features like burst buffers, etc. 

VELOC: Very Low Overhead Checkpointing System 

Provides users with an simple API while using complex heterogenous storage management tools under the hood 

## Introduction

Checkpointing could be used in AI to restore a model to a previous state 

High ratios of compute power to I/O bandwidth make checkpointing difficult 

Multi-level checkpointing: use storage on board nodes to hold checkpoint data instead of an external filesystem to reduce overhead at a slight reliability cost 
- not feasible at exascale due to heterogenous nature of storage systems 

## Overview of VELOC

### Hidden Complexity of Heterogeneous Storage 

VELOC API allows for users to declare critical memory regions that need to be a part of the checkpoint 

*** How? VELOC will resolve storage details behind the scences 
- this paper is very high level making it difficult to gain a good understanding 





