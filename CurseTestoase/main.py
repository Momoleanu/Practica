import turtle
from turtle import Turtle, Screen
from random import randint, choice

screen = Screen()
screen.setup(width=500, height=400)
user_bet = screen.textinput(title="Make your bet", prompt="Which turtle will win the race? Enter a color: ")
y_pos = [-70, -40, -10, 20, 50, 80]
colors = ["Red", "Green", "Black", "Blue", "Pink", "Brown"]
all_turtles=[]

for i in range(0, 6):
    new_turtle = Turtle("turtle")
    new_turtle.goto(x=-240, y=y_pos[i])
    new_turtle.color(colors[i])
    all_turtles.append(new_turtle)
    new_turtle.clear()


if user_bet:
    race = True

while race:
    for i in all_turtles:
        if i.xcor() > 220:
            race = False
            winning_color = i.pencolor()
            if winning_color == user_bet:
                print("You've won! ")
            else:
                print("You've lost! ")

        rand_distance = randint(0, 10)
        i.forward(rand_distance)

screen.exitonclick()
