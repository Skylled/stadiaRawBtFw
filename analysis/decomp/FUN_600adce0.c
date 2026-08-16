// 600adce0  FUN_600adce0  size=464 bytes
// --- callers ---
//   600f622a FUN_600f622a
// --- callees ---
//   600d92fc FUN_600d92fc
//   600d92f8 FUN_600d92f8
//   6006dfa4 FUN_6006dfa4
//   6006ddd8 FUN_6006ddd8
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006dbac FUN_6006dbac


undefined4 FUN_600adce0(int *param_1,char param_2,undefined4 param_3,ushort param_4)

{
  bool bVar1;
  int iVar2;
  ushort uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *local_14;
  ushort local_10;
  ushort local_e;
  int local_c;
  
  local_c = 0;
  iVar2 = FUN_6006dbac(0x262,DAT_600adeb0,0x70);
  bVar1 = false;
  if (iVar2 == 0) {
    *(undefined1 *)((int)param_1 + 0x2f) = 0x11;
    uVar4 = 0;
  }
  else {
    thunk_EXT_FUN_0000b572(iVar2,param_3,0x262);
    FUN_6006dfa4(param_1 + 8,iVar2);
    *(char *)((int)param_1 + 0x2f) = param_2;
    if (param_2 == '\0') {
      if ((short)param_1[10] == *(short *)((int)param_1 + 10)) {
        iVar2 = FUN_6006dbac(param_4 + 0x15,DAT_600adeb0,0x89);
        if (iVar2 == 0) {
          *(undefined1 *)((int)param_1 + 0x2f) = 0x11;
          uVar4 = 1;
        }
        else {
          thunk_EXT_FUN_0000b5ba(iVar2,0,param_4 + 0x15);
          *(undefined2 *)(iVar2 + 4) = 0xd;
          puVar5 = (undefined1 *)(iVar2 + 8 + (uint)*(ushort *)(iVar2 + 4));
          local_14 = puVar5 + 1;
          *puVar5 = 0xf;
          *(undefined2 *)(iVar2 + 2) = 1;
          for (local_e = 0; local_e < *(ushort *)((int)param_1 + 10); local_e = local_e + 1) {
            if (local_e == 0) {
              local_c = FUN_600d92f8(param_1 + 8);
            }
            else {
              local_c = FUN_600d92fc(local_c);
            }
            if (local_c == 0) {
              *(undefined1 *)((int)param_1 + 0x2f) = 10;
              break;
            }
            uVar3 = *(short *)(local_c + 6) + *(short *)(iVar2 + 2);
            if (param_4 < uVar3) {
              local_10 = (param_4 - uVar3) + *(short *)(local_c + 6);
              bVar1 = true;
            }
            else {
              local_10 = *(ushort *)(local_c + 6);
            }
            if (*(short *)(local_c + 2) != *(short *)((int)param_1 + (local_e + 4) * 2 + 4)) {
              *(undefined1 *)((int)param_1 + 0x2f) = 10;
              break;
            }
            thunk_EXT_FUN_0000b572(local_14,local_c + 9,local_10);
            if (!bVar1) {
              local_14 = local_14 + local_10;
            }
            *(ushort *)(iVar2 + 2) = local_10 + *(short *)(iVar2 + 2);
            if (bVar1) break;
          }
          if (*(short *)(iVar2 + 2) == 0) {
            *(undefined1 *)((int)param_1 + 0x2f) = 10;
            FUN_6006ddd8(iVar2,DAT_600adeb0,0xd3);
          }
          else if (*param_1 == 0) {
            *param_1 = iVar2;
          }
          else {
            FUN_6006ddd8(iVar2,DAT_600adeb0,0xd8);
          }
          uVar4 = 1;
        }
      }
      else {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 1;
    }
  }
  return uVar4;
}


