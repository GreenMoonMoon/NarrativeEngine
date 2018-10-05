# General Notes
The narrative engine is composed of 2(*3?*) distinc parts. The data structure, the generator and the interrest monitoring system.

The building blocks of strories are actors, their actions, their motivations, events, locations, etc. The chalenge is to define them for a computer. The current goal is to build a video game story line for the player to enact or affect. The later is a bit easier, since the player can unknowingly become the writer. While building full compeling stories proceduraly can be both expensive and extremely tricky, it isn't necessary to let the computer build everything. The simple approche would be to simply automate everything that can be automated and leave the rest for someone to write.


The templates, which will provide specific interpretation of the data
a template will be chosen by finding key elements in the context(game state)
and the data (actors, actions, motivations and such, etc.) will be applied to the template

Template can be extremely simple, small story structure that can be coupled to other template for a more complexe story structure. Most stories can be broken down in small pieces that act around and on each other
*Humor template could be desastrously hard to craft due to the shear number of humor pattern and theory out there.*

Templates are authored, but can be mixed if they don't conflict with each other.
These templates are bound by the context, if the context does not permit a template, then this template will not be chosen. This enable control over the story structure and developpment. Templates are always chosen based on current context, they do not affect the context therefore the game needs to generate a bunch of *leads* that could be used. The generated leads may or may not be affected by the player actions. A good idea would be to insert general leads for more authored content and specific ones based on the player interest for side content.
The game would use the template to align objects into their next states or to drive the simulation. Then depending on how frequently the game state is analysed
another temlate is applied to the current state. All previous actions are recorded, player wise or game wise as they can serve as pseudo-context or context for the next templates.
Stories can generaly be decomposed in multiple arc that follow similar pattern. With a handful of these pattern we can build compelling narrative easily. The second element are the actors and their motivation. Character psyche can be hard to write, harder still to generate with a computer but it can be helped by archetype templates. Motivations and goals can be picked up from enviroments, events or player actions. Archetypes can also help define behavior and descisions process of actors. Events caused by actors or the environments are what makes the narrative move foward.
## Basic Data Structure
Hold all narrative relevant data. Can be manipulated and used to actualyze the story within the game. This structure does not have any logic, it is mainly a tool to represent narrative structure within the game.
One key feature of this data structure will be to handle a growing list of componenet and their possible status.
### Component
This is the basic building part of the structure.
#### Declaration
To declare a new component, first indicate which component the new one inherit from, `Component` is the default if nothing is specified. Then indicate the name of this new component followed by square bracket containing possible status, the bracket can be left empty.

`Component {type} [<{status| ...}|>]`

To declare an instance of a component, first indicate the type of component followed byt the instance name and the desired status. The status is mandatory therefore it is good practice to setup default statuses when declaring component types.

`{type} {id} {status}`

The `type` and `status` are defined in advances, before declaring instances. Component can inherit from one another. For example:
```
Component Person [dead|alive]
Person Knight [chivalrous|coward]
Knight sirKnight alive
sirKnight chivalrous
```
Component can also inherit from multiple component by inserting a comma between Component types. The last declared name before the square brackets is the new component name:
```
Knight, Dragon Dragoneer []
```

This is valid, since Knight is an extention of Person. The type Component is the predefined default component type.

The `id` attribute groups component together. A component group can only contain one instance of each component. All component with the same id are considered part of the same *narrative entity*.
### States
### Actions

## Template
### narrative
The narrative template is the main narrative element.
### Archetype
Archetypes templates are used to define actors. 
## Generator
Generates all variables for the narrative engine. Uses various heuristic to output the most relevant variables to the current narrative. Generate the narrative structure by completing templates. Uses the IMS to make the narrative more compeling to the player.
## Interrest monitoring system
Gather all relevant data from the player playstyle. Such as which NPCs is spoken to the more often, which area is more explored, etc. These informations can be used to asing weight to various components. The Generator will then be able to use it to further personalyse the player experience.
# TODOs
- [x] Create the basic language for declaring [compoents](#component).
- [ ] Create a basic parser for reading and writing [component](#component) declarations.
- [ ] Create the structure for [States](#states) and [Actions](#actions).
- [ ] Refactor the paragraph about [narrative composition](#narrative-composition)
# Table of contents
- [General Notes](#general-notes)
    - [Basic Data Structure](#basic-data-structure)
        - [Component](#component)
            - [Declaration](#declaration)
        - [States](#states)
        - [Actions](#actions)
    - [Template](#template)
        - [narrative](#narrative)
        - [Archetype](#archetype)
    - [Generator](#generator)
    - [Interrest monitoring system](#interrest-monitoring-system)
- [TODOs](#todos)
- [Table of contents](#table-of-contents)