// 600988d0  FUN_600988d0  size=336 bytes
// --- callers ---
// --- callees ---
//   60098be8 FUN_60098be8
//   600d9380 FUN_600d9380
//   60098a24 FUN_60098a24
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600988d0(short *param_1)

{
  char cVar1;
  
  if (**(char **)(param_1 + 2) == '\0') {
    cVar1 = *DAT_60098a20;
    if (cVar1 == '\x03') {
      if (*param_1 == -0x3b4) {
        if (*(uint *)(DAT_60098a20 + 0x10) < *(uint *)(DAT_60098a20 + 8)) {
          FUN_60098a24();
        }
        else {
          *DAT_60098a20 = '\x04';
          if (DAT_60098a20[4] == '\0') {
            *(int *)(DAT_60098a20 + 0x18) =
                 *(int *)(DAT_60098a20 + 8) + *(int *)(DAT_60098a20 + 0x18);
            if (*(int *)(DAT_60098a20 + 0x14) != 0) {
              (**(code **)(DAT_60098a20 + 0x14))(0);
            }
          }
          else {
            *DAT_60098a20 = '\x05';
            FUN_60098be8();
          }
        }
      }
      else if (*(int *)(DAT_60098a20 + 0x14) != 0) {
        (**(code **)(DAT_60098a20 + 0x14))(2);
      }
    }
    else if (cVar1 == '\x05') {
      if (*param_1 == -0x3b2) {
        FUN_600d9380(0x32);
        if (*(int *)(DAT_60098a20 + 0x14) != 0) {
          (**(code **)(DAT_60098a20 + 0x14))(1);
        }
        thunk_EXT_FUN_0000b5ba(DAT_60098a20,0,0x20);
      }
      else if (*(int *)(DAT_60098a20 + 0x14) != 0) {
        (**(code **)(DAT_60098a20 + 0x14))(2);
      }
    }
    else if (cVar1 == '\x01') {
      if (*param_1 == *(short *)(DAT_60098a20 + 2)) {
        *DAT_60098a20 = '\x02';
        FUN_600d9380(0x32);
        if (DAT_60098a20[4] == '\0') {
          if (*(int *)(DAT_60098a20 + 0x14) != 0) {
            (**(code **)(DAT_60098a20 + 0x14))(0);
          }
        }
        else {
          *DAT_60098a20 = '\x03';
          FUN_60098a24();
        }
      }
      else if (*(int *)(DAT_60098a20 + 0x14) != 0) {
        (**(code **)(DAT_60098a20 + 0x14))(2);
      }
    }
  }
  else if (*(int *)(DAT_60098a20 + 0x14) != 0) {
    (**(code **)(DAT_60098a20 + 0x14))(2);
  }
  return;
}


