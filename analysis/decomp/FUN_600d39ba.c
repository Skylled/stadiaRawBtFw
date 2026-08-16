// 600d39ba  FUN_600d39ba  size=90 bytes
// --- callers ---
//   60066a74 keys__60066a74
//   600666f0 keys__600666f0
// --- callees ---
//   60065db0 FUN_60065db0
//   60066070 keys__60066070
//   601010c8 FUN_601010c8
//   60065dd8 FUN_60065dd8
//   600cb598 key_value_store__600cb598
//   600d6e14 FUN_600d6e14


uint FUN_600d39ba(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uStack_14;
  
  uVar6 = param_1;
  uVar7 = param_2;
  uStack_14 = param_4;
  iVar2 = FUN_600d6e14();
  if (iVar2 == 0) {
    uVar5 = keys__60066070(param_1,param_2,1);
  }
  else {
    uVar3 = FUN_60065db0(param_1);
    uVar4 = FUN_60065dd8(param_1);
    uStack_14 = uStack_14 & 0xffff;
    bVar1 = FUN_601010c8(uVar3,uVar4,(int)&uStack_14 + 2,0,uVar6,uVar7,param_3);
    uVar5 = (uint)bVar1;
    if (uVar5 == 0) {
      if (uStack_14._2_2_ == 1) {
        bVar1 = key_value_store__600cb598(uVar3,uVar4,param_2,1,0);
        uVar5 = (uint)bVar1;
      }
      else {
        uVar5 = 3;
      }
    }
  }
  return uVar5;
}


