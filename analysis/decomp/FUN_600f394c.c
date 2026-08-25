// 600f394c  FUN_600f394c  size=14 bytes
// --- callers ---
//   600fe00e FUN_600fe00e
// --- callees ---


undefined1 FUN_600f394c(undefined2 param_1,ushort param_2)

{
  int iVar1;
  ushort uStack_1c;
  undefined2 local_1a;
  int *piStack_18;
  int iStack_14;
  int iStack_10;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  
  uStack_9 = 0x80;
  uStack_a = (undefined1)param_1;
  uStack_b = (undefined1)((ushort)param_1 >> 8);
  uStack_1c = param_2;
  local_1a = param_1;
  iStack_10 = FUN_600af7c8(uStack_b);
  iStack_14 = FUN_600afd28(uStack_a);
  if ((((iStack_10 == 0) || (iStack_14 == 0)) || (uStack_1c < 0x17)) || (0x205 < uStack_1c)) {
    uStack_9 = 0x87;
  }
  else if (*(char *)(iStack_10 + 0x13) == '\x02') {
    iVar1 = FUN_600afd84(local_1a);
    if (iVar1 == 0) {
      piStack_18 = (int *)FUN_600afdf8(local_1a);
      if (piStack_18 != (int *)0x0) {
        *(ushort *)(*piStack_18 + 0x1a) = uStack_1c;
        *(undefined1 *)((int)piStack_18 + 0x31) = 5;
        uStack_9 = FUN_600ffada(*piStack_18,*(undefined2 *)((int)piStack_18 + 0x26),2,&uStack_1c);
      }
    }
    else {
      uStack_9 = 0x84;
    }
  }
  else {
    uStack_9 = 0x85;
  }
  return uStack_9;
}


