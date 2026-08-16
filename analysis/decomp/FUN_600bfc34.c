// 600bfc34  FUN_600bfc34  size=500 bytes
// --- callers ---
//   600fa34e FUN_600fa34e
//   600bd4bc FUN_600bd4bc
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013d168 thunk_EXT_FUN_0000b554


bool FUN_600bfc34(char *param_1,uint param_2,char *param_3,ushort param_4)

{
  int iVar1;
  bool bVar2;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [14];
  undefined1 auStack_18 [2];
  undefined1 auStack_16 [14];
  
  if (param_2 == param_4) {
    if (param_2 == 2) {
      if ((*param_1 == *param_3) && (param_1[1] == param_3[1])) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else if (param_2 == 4) {
      if (((*param_1 == *param_3) && (param_1[1] == param_3[1])) &&
         ((param_1[2] == param_3[2] && (param_1[3] == param_3[3])))) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      iVar1 = thunk_EXT_FUN_0000b554(param_1,param_3,param_2);
      bVar2 = iVar1 == 0;
    }
  }
  else if (param_4 < param_2) {
    if (param_2 == 4) {
      if (((*param_1 == '\0') && (param_1[1] == '\0')) &&
         ((param_1[2] == *param_3 && (param_1[3] == param_3[1])))) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      thunk_EXT_FUN_0000b572(auStack_18,param_1,0x10);
      thunk_EXT_FUN_0000b572(auStack_28,DAT_600bfe28,0x10);
      if (param_4 == 4) {
        thunk_EXT_FUN_0000b572(auStack_28,param_3,4);
      }
      else {
        thunk_EXT_FUN_0000b572(auStack_26,param_3,param_4);
      }
      iVar1 = thunk_EXT_FUN_0000b554(auStack_18,auStack_28,0x10);
      bVar2 = iVar1 == 0;
    }
  }
  else if (param_4 == 4) {
    if ((((*param_3 == '\0') && (param_3[1] == '\0')) && (param_3[2] == *param_1)) &&
       (param_3[3] == param_1[1])) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
  }
  else {
    thunk_EXT_FUN_0000b572(auStack_28,param_3,0x10);
    thunk_EXT_FUN_0000b572(auStack_18,DAT_600bfe28,0x10);
    if (param_2 == 4) {
      thunk_EXT_FUN_0000b572(auStack_18,param_1,4);
    }
    else {
      thunk_EXT_FUN_0000b572(auStack_16,param_1,param_2);
    }
    iVar1 = thunk_EXT_FUN_0000b554(auStack_18,auStack_28,0x10);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}


