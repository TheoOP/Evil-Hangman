#pragma once
#ifndef STATUS_H
#define STATUS_H
enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;

enum status { FAILURE, SUCCESS };
typedef enum status Status;
typedef void* Item;
typedef Item* Item_ptr;
#endif

