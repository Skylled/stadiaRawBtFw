// 600bd150  FUN_600bd150  size=810 bytes
// --- callers ---
//   600930dc FUN_600930dc
// --- callees ---
//   600bdb7c FUN_600bdb7c
//   600bd848 FUN_600bd848
//   600bd730 FUN_600bd730
//   600bd65c FUN_600bd65c
//   6004cb28 FUN_6004cb28


short FUN_600bd150(undefined2 *param_1,int *param_2)

{
  int iVar1;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined2 local_1a;
  undefined2 *local_18;
  undefined2 local_12;
  int local_10;
  short local_a;
  
  local_a = 0;
  local_1a = 0x1200;
  local_12 = 0x103;
  *param_2 = 0;
  if (param_1 == (undefined2 *)0x0) {
    return 0xb;
  }
  if ((*(char *)(param_1 + 4) == '\x01') && (*(int *)(DAT_600bd1a8 + 0xfc) != 0)) {
    local_10 = *(int *)(DAT_600bd1a8 + 0xfc);
  }
  else {
    local_10 = FUN_600bd65c();
    if (local_10 == 0) {
      return 6;
    }
  }
  *param_2 = local_10;
  iVar1 = FUN_600bdb7c(local_10,1,&local_1a);
  if (iVar1 == 0) {
    local_a = 7;
  }
  if (local_a == 0) {
    local_1c = (undefined1)((ushort)local_12 >> 8);
    local_18 = &local_1a;
    local_1b = (undefined1)local_12;
    iVar1 = FUN_600bd848(local_10,0x200,1,2,&local_1c);
    if (iVar1 == 0) {
      local_a = 7;
    }
  }
  if ((local_a == 0) && (*(char *)((int)param_1 + 9) != '\0')) {
    iVar1 = FUN_6004cb28((int)param_1 + 9);
    if (iVar1 + 1U < 0x101) {
      iVar1 = FUN_6004cb28((int)param_1 + 9);
      iVar1 = FUN_600bd848(local_10,0xb,8,iVar1 + 1,(int)param_1 + 9);
      if (iVar1 != 0) goto LAB_600bd25c;
    }
    local_a = 7;
  }
LAB_600bd25c:
  if ((local_a == 0) && (*(char *)((int)param_1 + 0x109) != '\0')) {
    iVar1 = FUN_6004cb28((int)param_1 + 0x109);
    if (iVar1 + 1U < 0x101) {
      iVar1 = FUN_6004cb28((int)param_1 + 0x109);
      iVar1 = FUN_600bd848(local_10,0x101,4,iVar1 + 1,(int)param_1 + 0x109);
      if (iVar1 != 0) goto LAB_600bd2b2;
    }
    local_a = 7;
  }
LAB_600bd2b2:
  if ((local_a == 0) && (*(char *)((int)param_1 + 0x209) != '\0')) {
    iVar1 = FUN_6004cb28((int)param_1 + 0x209);
    if (iVar1 + 1U < 0x101) {
      iVar1 = FUN_6004cb28((int)param_1 + 0x209);
      iVar1 = FUN_600bd848(local_10,10,8,iVar1 + 1,(int)param_1 + 0x209);
      if (iVar1 != 0) goto LAB_600bd306;
    }
    local_a = 7;
  }
LAB_600bd306:
  if (local_a == 0) {
    local_1c = (undefined1)((ushort)*param_1 >> 8);
    local_18 = &local_1a;
    local_1b = (undefined1)*param_1;
    iVar1 = FUN_600bd848(local_10,0x201,1,2,&local_1c);
    if (iVar1 == 0) {
      local_a = 7;
    }
  }
  if (local_a == 0) {
    local_1c = (undefined1)((ushort)param_1[2] >> 8);
    local_18 = &local_1a;
    local_1b = (undefined1)param_1[2];
    iVar1 = FUN_600bd848(local_10,0x202,1,2,&local_1c);
    if (iVar1 == 0) {
      local_a = 7;
    }
  }
  if (local_a == 0) {
    local_1c = (undefined1)((ushort)param_1[3] >> 8);
    local_18 = &local_1a;
    local_1b = (undefined1)param_1[3];
    iVar1 = FUN_600bd848(local_10,0x203,1,2,&local_1c);
    if (iVar1 == 0) {
      local_a = 7;
    }
  }
  if (local_a == 0) {
    local_1d = *(undefined1 *)(param_1 + 4);
    iVar1 = FUN_600bd848(local_10,0x204,5,1,&local_1d);
    if (iVar1 == 0) {
      local_a = 7;
    }
  }
  if (local_a == 0) {
    local_1c = (undefined1)((ushort)param_1[1] >> 8);
    local_18 = &local_1a;
    local_1b = (undefined1)param_1[1];
    iVar1 = FUN_600bd848(local_10,0x205,1,2,&local_1c);
    if (iVar1 == 0) {
      local_a = 7;
    }
  }
  if (local_a == 0) {
    if (*(char *)(param_1 + 4) == '\x01') {
      *(int *)(DAT_600bd480 + 0xfc) = local_10;
    }
  }
  else {
    FUN_600bd730(local_10);
  }
  return local_a;
}


