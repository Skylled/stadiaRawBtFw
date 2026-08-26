// 6004b4aa  FUN_6004b4aa  size=278 bytes
// --- callers ---
//   6004b5c0 FUN_6004b5c0
// --- callees ---


undefined8 FUN_6004b4aa(uint param_1,uint param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  uVar6 = param_1 & 0x22222222;
  uVar7 = param_1 & 0x11111111;
  uVar8 = param_1 & 0x44444444;
  param_1 = param_1 & 0x88888888;
  uVar9 = param_2 & 0x11111111;
  uVar5 = param_2 & 0x44444444;
  uVar4 = param_2 & 0x22222222;
  param_2 = param_2 & 0x88888888;
  uVar1 = ((ulonglong)uVar7 * (ulonglong)uVar9 ^ (ulonglong)uVar6 * (ulonglong)param_2 ^
           (ulonglong)uVar8 * (ulonglong)uVar5 ^ (ulonglong)param_1 * (ulonglong)uVar4) &
          0x1111111111111111;
  uVar2 = ((ulonglong)uVar7 * (ulonglong)uVar4 ^ (ulonglong)uVar9 * (ulonglong)uVar6 ^
           (ulonglong)param_2 * (ulonglong)uVar8 ^ (ulonglong)uVar5 * (ulonglong)param_1) &
          0x2222222222222222;
  local_30 = (uint)uVar1;
  uStack_2c = (uint)(uVar1 >> 0x20);
  uVar1 = ((ulonglong)uVar7 * (ulonglong)uVar5 ^ (ulonglong)uVar6 * (ulonglong)uVar4 ^
           (ulonglong)uVar9 * (ulonglong)uVar8 ^ (ulonglong)param_2 * (ulonglong)param_1) &
          0x4444444444444444;
  uVar3 = ((ulonglong)uVar8 * (ulonglong)uVar4 ^
           (ulonglong)uVar6 * (ulonglong)uVar5 ^ (ulonglong)uVar7 * (ulonglong)param_2 ^
          (ulonglong)uVar9 * (ulonglong)param_1) & 0x8888888888888888;
  return CONCAT44((uint)(uVar3 >> 0x20) | uStack_2c | (uint)(uVar2 >> 0x20) | (uint)(uVar1 >> 0x20),
                  (uint)uVar3 | local_30 | (uint)uVar2 | (uint)uVar1);
}


