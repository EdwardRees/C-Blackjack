#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "structs.h"
#include "hand.h"
#include "printer.h"

/**
 * Print out the option menu
 */
void print_menu(void)
{
  printf("[1] = Hit\n");
  printf("[2] = Hold\n");
}

/**
 * Play game
 * 
 * @param deck deck to use
 * @param player1 first player hand
 * @param player2 second player hand
 */
void interactive(deck *deck, hand *player1, hand *player2)
{
  add_card(player1, deck);
  add_card(player2, deck);
  add_card(player1, deck);
  add_card(player2, deck);
  while (true)
  {
    if (contains_blackjack(player1))
    {
      printf("Player 1 got blackjack!\n");
      break;
    }
    else if (contains_blackjack(player2))
    {
      printf("Player 2 got blackjack!\n");
      break;
    }
    if (!player1->held && !player1->has_busted)
    {
      char choice;
      printf("Player 1: ");
      print_hand(player1);
      printf("\n");
      print_menu();
      scanf("%c", &choice);
      while (choice != '1' && choice != '2')
      {
        printf("Invalid choice, try again!\n");
        print_menu();
        scanf("%c", &choice);
      }
      if (choice == '1')
      {
        add_card(player1, deck);
        if (has_busted(player1))
        {
          bust(player1);
        }
      }
      else if (choice == '2')
      {
        hold(player1);
      }
    }
    if (!player2->held && !player2->has_busted)
    {
      char choice;
      printf("Player 2: ");
      print_hand(player2);
      printf("\n");
      print_menu();
      scanf("%c", &choice);
      while (choice != '1' && choice != '2')
      {
        printf("Invalid choice, try again!\n");
        print_menu();
        scanf("%c", &choice);
      }
      if (choice == '1')
      {
        add_card(player2, deck);
        if (has_busted(player2))
        {
          bust(player2);
        }
      }
      else if (choice == '2')
      {
        hold(player2);
      }
    }
    if ((player1->held || player1->has_busted) && (player2->held || player2->has_busted))
    {
      break;
    }
  }
  if (!contains_blackjack(player1) && !contains_blackjack(player2))
  {
    if (get_hand_value(player1) > get_hand_value(player2) && !player1->has_busted)
    {
      printf("Player 1 wins!\n");
    }
    else if (get_hand_value(player1) > get_hand_value(player2) && player1->has_busted)
    {
      printf("Player 2 wins!\n");
    }
    else if (get_hand_value(player1) < get_hand_value(player2) && !player2->has_busted)
    {
      printf("Player 2 wins!\n");
    }
    else if (get_hand_value(player1) < get_hand_value(player2) && player2->has_busted)
    {
      printf("Player 1 wins!\n");
    }

    else
    {
      printf("Tie game!\n");
    }
  }
  printf("The hands were: \nPlayer1: ");
  print_hand(player1);
  printf("\n");
  printf("Player 2: ");
  print_hand(player2);
  printf("\n");
}

/**
 * Single player, play against a computer
 * 
 * @param deck deck to use 
 * @param player player's hand to use
 * @param cpu cpu hand to use
 */
void single_player(deck *deck, hand *player, hand *cpu, bool show_hand)
{
  add_card(player, deck);
  add_card(cpu, deck);
  add_card(player, deck);
  add_card(cpu, deck);
  while (true)
  {
    if (contains_blackjack(player))
    {
      printf("You got blackjack!\n");
      break;
    }
    else if (contains_blackjack(cpu))
    {
      printf("The Computer got blackjack!\n");
      break;
    }
    if (!player->held && !player->has_busted)
    {
      char choice;
      printf("Your turn: ");
      print_hand(player);
      printf("\n");
      print_menu();
      scanf("%c", &choice);
      while (choice != '1' && choice != '2')
      {
        printf("Invalid choice, try again!\n");
        print_menu();
        scanf("%c", &choice);
      }
      if (choice == '1')
      {
        add_card(player, deck);
        if (has_busted(player))
        {
          bust(player);
        }
      }
      else if (choice == '2')
      {
        hold(player);
      }
    }
    if (!cpu->held && !cpu->has_busted)
    {
      printf("Computer Choice: ");
      if (get_hand_value(cpu) < 16)
      {
        if (show_hand)
        {
          print_hand(cpu);
          printf("\n");
        }
        printf("Hit!\n");
        add_card(cpu, deck);
        if (has_busted(cpu))
        {
          bust(cpu);
        }
      }
      else
      {
        printf("Hold!\n");
        printf("Computer hand sums to at least 16, holding!\n");
        hold(cpu);
      }
    }
    if ((player->held || player->has_busted) && (cpu->held || cpu->has_busted))
    {
      break;
    }
  }
  printf("\n");
  if (!contains_blackjack(player) && !contains_blackjack(cpu))
  {
    if (get_hand_value(player) > get_hand_value(cpu) && !player->has_busted)
    {
      printf("You win!\n");
    }
    else if (get_hand_value(player) > get_hand_value(cpu) && player->has_busted)
    {
      printf("Computer wins!\n");
    }
    else if (get_hand_value(player) < get_hand_value(cpu) && !cpu->has_busted)
    {
      printf("Computer wins!\n");
    }
    else if (get_hand_value(player) < get_hand_value(cpu) && cpu->has_busted)
    {
      printf("You win!\n");
    }

    else
    {
      printf("Tie game!\n");
    }
  }
  printf("\n");
  printf("The hands were: \nYou: ");
  print_hand(player);
  printf("\nComputer: ");
  print_hand(cpu);
  printf("\n");
}