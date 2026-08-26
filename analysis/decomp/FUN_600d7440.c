// 600d7440  FUN_600d7440  size=112 bytes
// --- callers ---
//   600d74b0 FUN_600d74b0
// --- callees ---
//   600667fc FUN_600667fc
//   6004cb28 FUN_6004cb28
//   60065dd8 FUN_60065dd8
//   6013d168 thunk_EXT_FUN_0000b554
//   600d4550 FUN_600d4550


int FUN_600d7440(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_48;
  uint local_44;
  undefined4 local_30;
  uint local_2c;
  
  iVar6 = 0;
  FUN_600667fc(&local_48,param_1,param_2);
  while( true ) {
    iVar3 = FUN_60065dd8(iVar6);
    uVar4 = 0;
    if (iVar3 != 0) {
      uVar4 = FUN_6004cb28();
    }
    FUN_600667fc(&local_30,uVar4,iVar3);
    uVar2 = local_2c;
    uVar1 = local_44;
    uVar5 = local_44;
    if (local_2c <= local_44) {
      uVar5 = local_2c;
    }
    if (((uVar5 == 0) || (iVar3 = thunk_EXT_FUN_0000b554(local_48,local_30), iVar3 == 0)) &&
       (uVar1 == uVar2)) break;
    iVar6 = iVar6 + 1;
    FUN_600d4550(&local_30);
    if (iVar6 == 0x43) {
LAB_600d7496:
      FUN_600d4550(&local_48);
      return iVar6;
    }
  }
  FUN_600d4550(&local_30);
  goto LAB_600d7496;
}


