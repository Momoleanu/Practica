from turtle import Turtle
from header import *


class Snake:
    def __init__(self):
        self.segm = []
        self.create_snake()
        self.head = self.segm[0]

    def create_snake(self):
        for i in STARTING_POSITIONS:
            self.add(i)

    def add(self, position):
        snake_part = Turtle("square")
        snake_part.color("white")
        snake_part.penup()
        snake_part.goto(position)
        self.segm.append(snake_part)

    def extend(self):
        self.add(self.segm[-1].position())

    def move(self):
        for snk in range(len(self.segm) - 1, 0, -1):
            new_x = self.segm[snk - 1].xcor()
            new_y = self.segm[snk - 1].ycor()
            self.segm[snk].goto(new_x, new_y)
        self.segm[0].forward(MOVE_DISTANCE)

    def up(self):
        if self.head.heading() != DOWN:
            self.head.setheading(UP)

    def down(self):
        if self.head.heading() != UP:
            self.head.setheading(DOWN)

    def left(self):
        if self.head.heading() != RIGHT:
            self.head.setheading(LEFT)

    def right(self):
        if self.head.heading() != LEFT:
            self.head.setheading(RIGHT)
