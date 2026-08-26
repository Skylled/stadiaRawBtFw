// 600d4664  FUN_600d4664  size=48 bytes
// --- callers ---
// --- callees ---
//   6005e3d0 bug_report__6005e3d0
//   6005e25c FUN_6005e25c
//   60071870 FUN_60071870


uint FUN_600d4664(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 local_536;
  uint local_534;
  uint local_530;
  uint local_52c;
  int local_528;
  undefined1 *local_524;
  undefined4 local_520;
  undefined4 uStack_51c;
  undefined1 auStack_518 [1288];
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  iVar2 = FUN_60071870();
  if (iVar2 == 0) {
    return 0;
  }
  FUN_6005e25c(param_1);
  if ((*(char *)(param_1 + 4) == '\0') &&
     (uVar3 = bug_report__6005e3d0(param_1), (uVar3 & 0xff) != 0)) {
    return uVar3;
  }
  local_52c = FUN_6010248a(param_2,0x7b);
  if (((local_52c != 0) && (uVar3 = FUN_60102502(param_2,DAT_6005e584), uVar3 != 0)) &&
     (local_52c <= uVar3)) {
    local_524 = auStack_518;
    local_528 = (uVar3 - local_52c) + 1;
    local_520 = 0x50;
    uStack_51c = 0;
    uVar3 = parser__600834a4(&local_52c);
    local_534 = uVar3 & 0xff;
    if (local_534 != 0) {
      return uVar3;
    }
    local_530 = local_534;
    uVar3 = FUN_600dfd24(&local_52c,DAT_6005e588,&local_534);
    if ((uVar3 & 0xff) != 0) {
      return uVar3;
    }
    if (local_534 < 0x201) {
      iVar4 = param_1 + 0x10;
      local_536 = (undefined2)local_534;
      iVar5 = *(int *)(param_1 + 8);
      iVar2 = bug_report__6005e200(iVar4);
      iVar1 = bug_report__6005e200(iVar4,2);
      uVar3 = FUN_600d4652(*(undefined4 *)(param_1 + 0xc));
      if (uVar3 < (uint)(iVar2 + iVar1 + iVar5)) {
        return 8;
      }
      uVar3 = FUN_60101848(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8),&local_536);
      if ((uVar3 & 0xff) != 0) {
        return uVar3;
      }
      iVar2 = bug_report__6005e200(iVar4,2);
      iVar2 = *(int *)(param_1 + 8) + iVar2;
      *(int *)(param_1 + 8) = iVar2;
      uVar3 = FUN_60101848(*(undefined4 *)(param_1 + 0xc),iVar2,local_530,local_536);
      if ((uVar3 & 0xff) != 0) {
        return uVar3;
      }
      iVar2 = bug_report__6005e200(iVar4,local_536);
      *(int *)(param_1 + 8) = iVar2 + *(int *)(param_1 + 8);
      return 0;
    }
  }
  return 3;
}


