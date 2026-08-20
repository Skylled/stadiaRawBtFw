// 600e9414  FUN_600e9414  size=162 bytes
// --- callers ---
//   6008b970 bcm__6008b970
// --- callees ---


undefined8 FUN_600e9414(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint local_38;
  uint uStack_34;
  uint local_30;
  uint uStack_2c;
  
  iVar7 = 0x40;
  if ((int)param_1[1] < 2) {
    uVar3 = 0;
  }
  else {
    uVar3 = ((uint *)*param_1)[1];
  }
  local_30 = 0;
  uStack_2c = 0;
  local_38 = 1;
  uStack_34 = 0;
  do {
    uVar1 = -(uint)((local_38 & 1) != 0);
    uVar5 = -(local_38 & 1) & *(uint *)*param_1;
    uVar6 = uVar1 & uVar3;
    uVar4 = uStack_34 ^ uVar6;
    uVar2 = local_38 & uVar5;
    uVar5 = (uint)((uVar4 & 1) != 0) << 0x1f | (local_38 ^ uVar5) >> 1;
    local_38 = uVar2 + uVar5;
    uStack_34 = (uStack_34 & uVar6) + (uVar4 >> 1) + (uint)CARRY4(uVar2,uVar5);
    local_30 = (uint)((uStack_2c & 1) != 0) << 0x1f | local_30 >> 1;
    uStack_2c = (uStack_2c >> 1) + (uVar1 & 0x80000000);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  return CONCAT44(uStack_2c,local_30);
}


