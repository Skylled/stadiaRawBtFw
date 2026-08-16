// 600c0294  FUN_600c0294  size=300 bytes
// --- callers ---
// --- callees ---
//   600c1548 FUN_600c1548
//   600fabac FUN_600fabac
//   600c1a34 FUN_600c1a34
//   600c25ac FUN_600c25ac
//   600c19f4 FUN_600c19f4


void FUN_600c0294(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_9;
  
  switch(*(undefined1 *)(param_1 + 0x194)) {
  case 4:
  case 5:
    if (*(char *)(param_1 + 0x26) == '\0') {
      iVar1 = FUN_600c25ac(param_1);
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x24) = 4;
        local_9 = *(undefined1 *)(param_1 + 0x24);
        FUN_600c1a34(param_1,0x17,&local_9);
        return;
      }
    }
    else {
      FUN_600fabac(param_1,0,&switchD_600c02ae::switchdataD_600c02b4,*(char *)(param_1 + 0x26),
                   param_2);
    }
    if (*(char *)(param_1 + 0x194) == '\x04') {
      FUN_600c1a34(param_1,0x20,0);
    }
    else {
      FUN_600c19f4(10);
      FUN_600c1a34(param_1,0x21,0);
    }
    break;
  case 6:
  case 7:
    iVar1 = FUN_600c25ac(param_1);
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x24) = 4;
      local_9 = *(undefined1 *)(param_1 + 0x24);
      FUN_600c1a34(param_1,0x17,&local_9);
    }
    else {
      if (*(char *)(param_1 + 0x26) == '\x01') {
        FUN_600fabac(param_1,0);
      }
      *(char *)(param_1 + 0x199) = *(char *)(param_1 + 0x199) + '\x01';
      if (*(byte *)(param_1 + 0x199) < 0x14) {
        FUN_600c19f4(8);
        *(ushort *)(param_1 + 0x28) = *(ushort *)(param_1 + 0x28) & 0xff7f;
        FUN_600c1548(param_1);
      }
      else {
        FUN_600c1a34(param_1,0x20,0);
      }
    }
    break;
  case 8:
    if (*(char *)(param_1 + 0x26) == '\x01') {
      FUN_600fabac(param_1,0,&switchD_600c02ae::switchdataD_600c02b4,1,param_2);
    }
    FUN_600c1a34(param_1,0x20,0);
  }
  return;
}


