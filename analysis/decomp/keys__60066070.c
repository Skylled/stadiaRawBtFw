// 60066070  keys__60066070  size=200 bytes
// src: keys.cc
// --- callers ---
//   600d708c FUN_600d708c
//   600d6f7e FUN_600d6f7e
//   60051240 main__60051240
//   600d72b8 FUN_600d72b8
//   600d6eca FUN_600d6eca
//   600764fc input_task__600764fc
//   600d6f24 FUN_600d6f24
//   600d6fd8 FUN_600d6fd8
//   600d7032 FUN_600d7032
//   600d72ec FUN_600d72ec
//   600d39ba FUN_600d39ba
//   6005d3b4 thermal__6005d3b4
//   600d70e6 FUN_600d70e6
//   600d382e FUN_600d382e
// --- callees ---
//   600d37b8 FUN_600d37b8
//   60051120 FUN_60051120
//   6013d3a0 thunk_EXT_FUN_0000b572
//   60065d1c keys__60065d1c
//   6010165c FUN_6010165c
//   60065ccc FUN_60065ccc
//   600d37ac FUN_600d37ac
//   6010209a FUN_6010209a


/* src: keys.cc */

uint keys__60066070(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  ushort local_ae;
  undefined1 auStack_ac [8];
  undefined1 auStack_a4 [144];
  byte local_14;
  
  iVar1 = FUN_60065ccc();
  if (iVar1 == DAT_60066144) {
    FUN_60051120(auStack_ac,DAT_60066148,0x2db,3);
    uVar3 = DAT_6006614c;
  }
  else {
    if (*(char *)(iVar1 + 0x18) == '\0') {
      return 5;
    }
    uVar2 = keys__60065d1c(iVar1 + 8,&local_ae);
    if ((uVar2 & 0xff) != 0) {
      return uVar2;
    }
    if (local_ae == param_3) {
      if (*(char *)(iVar1 + 0x18) != '\0') {
        switch(*(undefined1 *)(iVar1 + 0xc)) {
        case 0:
          FUN_6010165c(0x28,DAT_60066148,0x2e5,DAT_60066154,*(undefined4 *)(iVar1 + 8));
          return 3;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xb:
          thunk_EXT_FUN_0000b572(param_2,iVar1 + 0x10);
          return 0;
        default:
          FUN_6010165c(0x28,DAT_60066148,0x309,DAT_60066158,*(undefined4 *)(iVar1 + 8));
          return 0xd;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_6010209a();
    }
    FUN_60051120(auStack_ac,DAT_60066148,0x2df,3);
    uVar3 = DAT_60066150;
  }
  FUN_600d37ac(auStack_a4,uVar3);
  FUN_600d37b8(auStack_ac);
  return (uint)local_14;
}


