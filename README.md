# Zappy - Epitech Project

The repository for the Zappy project.

<img src=".github/assets_readme/Zappy_picture.jpg" alt="picture zappy" width="540" height="360">

<img src=".github/assets_readme/Epitech_logo.png" alt="logo Epitech">

---


## Table of contents

[1. The purpose of the project](#titre1)<br />
[2. How to use Zappy](#titre2)<br />
[3. How to launch](#titre3)<br />
[4. People on the project](#titre4)<br />


---


## <a id="titre1"></a>1. The purpose of the project


Welcome to "Zappy" – an electrifying network game that will spark your competitive spirit! In this thrilling project, we aim to create an engaging multiplayer experience where teams battle it out on a dynamic tile-based map filled with valuable resources.

The primary objective of Zappy is to lead your team to victory by being the first to have at least six players reach the maximum elevation. But beware, the path to triumph is riddled with challenges and intense competition. Strategic decision-making, efficient resource management, and effective teamwork will be the keys to success.

As you explore the following pages, you will uncover the intricacies of the game's mechanics and the constraints that shape this electrifying adventure. From understanding the layout of the map and its resource distribution to devising winning strategies, you'll gain valuable insights into how to outmaneuver your opponents.

Prepare to immerse yourself in a world where lightning-fast reflexes and cunning tactics reign supreme. Collaborate closely with your teammates, navigate the ever-changing terrain, and capitalize on the available resources to surge ahead in the race to the highest elevation.

Get ready to embrace the pulse-pounding excitement of Zappy, where lightning strikes and fortunes change in an instant. May your team harness the power of strategy and skill to outshine the competition and emerge as champions in this electrifying network game!


---


## <a id="titre2"></a>2. How to use Zappy


...


---


## <a id="titre3"></a>3. How to launch the AI

```sh
> make AI
> /zappy_ai -p port -n name -h machine
    port is the port number
    name is the name of the team
    machine is the name of the machine; localhost by default
```

## <a id="titre3"></a>4. How to launch the GUI

To run the project:

```sh
> make GUI
> ./zappy_ai -p port -h machine
    port is the port number
    machine is the name of the machine; localhost by default
```

## <a id="titre3"></a>5. How to launch the Server

```sh
> make server
> ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
    port            is the port number
    width           is the width of the world
    height          is the height of the world
    nameX           is the name of the team X
    clientsNb       is the number of authorized clients per team
    freq            is the reciprocal of time unit for execution of actions
```

## Incantation

In order to win in zappy you and all the member of your team must reach lvl 8 (at least 6 of them), by collecting some resource and starting the incantation ritual. There exist different resource: linemate, deramere, sibur, mendiane, phiras and thystame.
Those resource will spawn depending of there density and the size of the map.

Here the conditions to reach the next lvl of a player:

| elevation | nb of players | Linemate | Deraumere | Sibur | Mendiane | Phiras | Thystame |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 1->2 | 1 | 1 | 0 | 0 | 0 | 0 | 0 |
| 2->3 | 2 | 1 | 1 | 1 | 0 | 0 | 0 |
| 3->4 | 2 | 2 | 0 | 1 | 0 | 2 | 0 |
| 4->5 | 4 | 1 | 1 | 2 | 0 | 1 | 0 |
| 5->6 | 4 | 1 | 2 | 1 | 3 | 0 | 0 |
| 6->7 | 6 | 1 | 2 | 3 | 0 | 1 | 0 |
| 7->8 | 6 | 2 | 2 | 2 | 2 | 2 | 1 |

## <a id="titre4"></a>.6 Contributors

| [<img src="https://github.com/Shaladur.png?size=85" width=85><br><sub>Bastien Rodrigues</sub>](https://github.com/Shaladur) | [<img src="https://github.com/Cyprien-nguyen-van-vien.png?size=85" width=85><br><sub>Cyprien Nguyen-Van-Vien</sub>](https://github.com/Cyprien-nguyen-van-vien) | [<img src="https://github.com/damienBC.png?size=85" width=85><br><sub>Damien Benais-Captal</sub>](https://github.com/damienBC) | [<img src="https://github.com/Pierrelouisleroy.png?size=85" width=85><br><sub>Pierre-Louis Leroy</sub>](https://github.com/Pierrelouisleroy) | [<img src="https://github.com/Hinivir.png?size=85" width=85><br><sub>Viktor Bruggeman</sub>](https://github.com/Hinivir) | [<img src="https://github.com/Lipatant.png?size=85" width=85><br><sub>Virgile Berrier</sub>](https://github.com/Lipatant)
| :--: | :--: | :--: | :--: | :--: | :--: |

bastien.rodrigues@epitech.eu  
cyprien.nguyen-van-vien@epitech.eu  
damien.benais-captal@epitech.eu  
pierre-louis.leroy@epitech.eu  
viktor.bruggeman@epitech.eu  
virgile.berrier@epitech.eu  
