// 6009486c  FUN_6009486c  size=214 bytes
// --- callers ---
// --- callees ---
//   600fa2cc FUN_600fa2cc
//   600ef44c FUN_600ef44c
//   600ee9f6 FUN_600ee9f6
//   600fa2e4 FUN_600fa2e4
//   600eec5a FUN_600eec5a
//   600fa300 FUN_600fa300


void FUN_6009486c(short param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_40 [4];
  short local_3c;
  short local_3a;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int local_24;
  short local_20;
  short local_1e;
  int local_1c;
  
  local_1c = 0;
  local_1e = 0;
  local_20 = 0;
  local_24 = FUN_600ef44c(*(undefined2 *)(DAT_60094964 + 0x5c4));
  iVar1 = local_24;
  if ((param_1 == 0) || (param_1 == -0xc)) {
    while (iVar1 != 0) {
      local_1c = FUN_600fa2e4(*(undefined4 *)(DAT_60094964 + 0x5c0),0,local_1c);
      iVar1 = local_1c;
      if (((local_1c != 0) &&
          (iVar2 = FUN_600fa2cc(local_1c,&local_38), iVar1 = local_1c, iVar2 != 0)) &&
         (iVar2 = FUN_600fa300(local_1c,7,auStack_40), iVar1 = local_1c, iVar2 != 0)) {
        local_1e = local_3c;
        local_20 = local_3a;
        if (((local_3c != 0) && (local_3a != 0)) && (local_24 != 0)) {
          FUN_600eec5a(local_24,local_3c,local_3a,local_38,local_34,uStack_30,uStack_2c,uStack_28,1)
          ;
          iVar1 = local_1c;
        }
      }
    }
  }
  if (local_24 != 0) {
    FUN_600ee9f6(*(undefined2 *)(DAT_60094964 + 0x5c4),local_24);
  }
  FUN_6006ddd8(*(undefined4 *)(DAT_60094964 + 0x5c0),DAT_60094968,0x373);
  *(undefined4 *)(DAT_60094964 + 0x5c0) = 0;
  *(undefined2 *)(DAT_60094964 + 0x5c4) = 0;
  return;
}


