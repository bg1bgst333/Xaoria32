// ヘッダのインクルード
// 独自のヘッダ
#include "Player.h"	// CPlayer
#include "Shot.h"	// CShot
#include "Explosion.h"	// CExplosion
#include "GameScene.h"	// CGameScene
#include "EnemyMap.h"	// CEnemyMap
#include "resource.h"	// リソース.

// コンストラクタCPlayer
CPlayer::CPlayer() : CCharacter(){

	// メンバの初期化.
	m_bDown = FALSE;	// m_bDownにFALSEをセット.
	m_bUp = FALSE;	// m_bUpにFALSEをセット.
	m_bRight = FALSE;	// m_bRightにFALSEをセット.
	m_bLeft = FALSE;	// m_bLeftにFALSEをセット.
	m_iNo = 0;	// m_iNoに0をセット.
	m_vecpShotList.clear(); // m_vecpShotList.clearでクリア.
	m_iShotIdx = 0;	// m_iShotIdxに0をセット.
	m_nState = 0;	// m_nStateに0をセット.
	m_pExplosion = NULL;	// m_pExplosionにNULLをセット.
	m_dwRestartInterval = 0;	// m_dwRestartIntervalに0をセット.
	m_dwRestartTimerStart = 0;	// m_dwRestartTimerStartに0をセット.
	m_bClear = FALSE;

}

// デストラクタCPlayer(CScene *pScene)
CPlayer::CPlayer(CScene *pScene) : CCharacter(pScene){

	// メンバの初期化.
	m_bDown = FALSE;	// m_bDownにFALSEをセット.
	m_bUp = FALSE;	// m_bUpにFALSEをセット.
	m_bRight = FALSE;	// m_bRightにFALSEをセット.
	m_bLeft = FALSE;	// m_bLeftにFALSEをセット.
	m_iNo = 0;	// m_iNoに0をセット.
	m_vecpShotList.clear(); // m_vecpShotList.clearでクリア.
	m_iShotIdx = 0;	// m_iShotIdxに0をセット.
	m_nState = 0;	// m_nStateに0をセット.
	m_pExplosion = NULL;	// m_pExplosionにNULLをセット.
	m_dwRestartInterval = 0;	// m_dwRestartIntervalに0をセット.
	m_dwRestartTimerStart = 0;	// m_dwRestartTimerStartに0をセット.
	m_bClear = FALSE;

}

// デストラクタ~CPlayer()
CPlayer::~CPlayer(){

	// メンバの終了処理.
	m_iNo = 0;	// m_iNoに0をセット.

	// クリア
	Clear();	// Clearでフラグのクリア.

	// 破棄.
	Destroy();	// Destroyで破棄.

}

// キャラクターの破棄Destroy.
void CPlayer::Destroy(){

	// ショットの破棄.
	for (std::vector<CSharedObject *>::iterator itor = m_vecpShotList.begin(); itor != m_vecpShotList.end(); itor++){	// リスト全ての破棄.
		if ((*itor) != NULL){	// (*itor)がNULLじゃない時.
			(*itor)->Destroy();	// (*itor)->Destroyで破棄.
			delete (*itor);	// deleteで(*Itor)を破棄.
			(*itor) = NULL;	// NULLをセット.
		}
	}
	m_vecpShotList.clear();	// クリア.
	m_nState = 0;	// m_nStateに0をセット.
	m_bClear = FALSE;

	// エクスプロージョンの破棄.
	if (m_pExplosion != NULL){	// m_pExplosionがNULLでない.
		m_pExplosion->Destroy();	// 破棄.
		delete m_pExplosion;	// 削除.
		m_pExplosion = NULL;	// NULLをセット.
	}
	
	// 親クラスのメンバ関数.
	CCharacter::Destroy();	// CCharacter::Destroyで破棄.

}

// マップの移動状態をクリア.
void CPlayer::Clear(){

	// フラグのクリア.
	m_bDown = FALSE;	// m_bDownにFALSEをセット.
	m_bUp = FALSE;	// m_bUpにFALSEをセット.
	m_bRight = FALSE;	// m_bRightにFALSEをセット.
	m_bLeft = FALSE;	// m_bLeftにFALSEをセット.
	m_bShot = FALSE;	// m_bShotにFALSEをセット.

}

// マップの視点を下に移動Down.(マップ自体は上に移動.)
void CPlayer::Down(){

	// 下のフラグ.
	m_bDown = TRUE;	// m_bDownにTRUEをセット.

}

// マップの視点を上に移動Up.(マップ自体は下に移動.)
void CPlayer::Up(){

	// 上のフラグ.
	m_bUp = TRUE;	// m_bUpにTRUEをセット.

}

// マップの視点を右に移動Right.(マップ自体は左に移動.)
void CPlayer::Right(){

	// 右のフラグ.
	m_bRight = TRUE;	// m_bRightにTRUEをセット.

}

// マップの視点を左に移動Ledt.(マップ自体は右に移動.))
void CPlayer::Left(){

	// 左のフラグ.
	m_bLeft = TRUE;	// m_bLeftにTRUEをセット.

}

// ショット発射.
void CPlayer::Shot(){

	// ショットフラグ.
	m_bShot = TRUE;	// m_bShotにTRUEをセット.

}

// 処理をするProc.
int CPlayer::Proc(){

	// 下.
	if (m_bDown){	// 下が押された時.
		m_y++;	// m_yを増やす.
		if (m_y >= 480 - 32){	// 上限超.
			m_y = 480 - 32;	// 上限.
		}
	}
	// 上.
	if (m_bUp){	// 上が押された時.
		m_y--;	// m_yを減らす.
		if (m_y <= 0){		// 下限超.
			m_y = 0;	// 下限.
		}
	}
	Set(0);	// 中央をセット.
	// 右.
	if (m_bRight){	// 右が押された時.
		m_x++;	// m_xを増やす.
		if (m_x >= 640 - 32){	// 上限超.
			m_x = 640 - 32;	// 上限.
		}
		Set(1);	// 右をセット.
	}
	// 左.
	if (m_bLeft){	// 左が押された時.
		m_x--;	// m_xを減らす.
		if (m_x <= 0){		// 下限超.
			m_x = 0;	// 下限.
		}
		Set(2);	// 左をセット.
	}

#if 1
	// ループ.
	// 発射.
	for (int k = 0, m = m_iShotIdx; k < m_vecpShotList.size(); k++){
		int iState = ((CShot *)m_vecpShotList[m])->Get();	// iState取得.
		if (iState == 0){	// ショット状態が0なら.
			if (GetState() == 0){	// プレイヤーの状態が0なら.
				if (m_bShot){	// ショットが押された時.
					((CShot *)m_vecpShotList[m])->Set(1);	// 1をセット.
					m_iShotIdx++;	// 1増やす.
					if (m_iShotIdx >= m_vecpShotList.size()){	// サイズ以上.
						m_iShotIdx = 0;	// 0に戻す.
					}
					break;	// 抜ける.
				}
			}
		}
		else if (iState == 1){
			((CShot *)m_vecpShotList[m])->m_y -= 8;	// y座標を8減らす.
			if (((CShot *)m_vecpShotList[m])->m_y <= -32){	// -32以下.
				((CShot *)m_vecpShotList[m])->Set(2);
			}
		}
		m++;
		if (m >= m_vecpShotList.size()){
			m = 0;
		}
	}
	BOOL bClear = TRUE;
	// 当たり判定.
	CGameScene *pGameScene = (CGameScene *)m_pScene;	// pGameSceneにキャスト.
	CEnemyMap *pEnemyMap = pGameScene->m_pEnemyMap;	// pEnemyMapを取得.
	CEnemies *pEnemies = pEnemyMap->m_pEnemies;	// pEnemiesの取得.
	CMap *pMap = pGameScene->m_pMap;	// pMapを取得.
	int n = pEnemyMap->m_vecEnemyMapDataList.size();	// サイズを取得.
	for (int i = 0; i < n; i++){	// n繰り返す.
		// 敵とショットの当たり判定.
		for (int j = 0; j < m_vecpShotList.size(); j++){
			int iState = ((CShot *)m_vecpShotList[j])->Get();	// iState取得.
			if (iState == 1){	// 1なら.
				if (pEnemyMap->m_vecEnemyMapDataList[i]->m_nState == 1){	// 表示.
					int ex = pEnemyMap->m_vecEnemyMapDataList[i]->m_x - pMap->m_iScreenRX;	// 敵の画面座標ex.(こちらは右が正, なので正.)
					int ey = pMap->m_iScreenUY - pEnemyMap->m_vecEnemyMapDataList[i]->m_y;	// 敵の画面座標ey.(こちらは上が正, なので逆.)
					int ew = pEnemies->m_vecEnemiesList[pEnemyMap->m_vecEnemyMapDataList[i]->m_nEnemyNo]->m_iWidth;	// 幅.
					int eh = pEnemies->m_vecEnemiesList[pEnemyMap->m_vecEnemyMapDataList[i]->m_nEnemyNo]->m_iHeight;	// 高さ.
					int sx = ((CShot *)m_vecpShotList[j])->m_x;	// ショットx.
					int sy = ((CShot *)m_vecpShotList[j])->m_y;	// ショットy.
					int sw = ((CShot *)m_vecpShotList[j])->m_iWidth;	// 幅.
					int sh = ((CShot *)m_vecpShotList[j])->m_iHeight;	// 高さ.
					if ((ex <= sx && sx <= ex + ew && ey <= sy && sy <= ey + eh)		// ショットの左上.
						|| (sx <= ex && ex <= sx + sw && ey <= sy && sy <= ey + eh)		// ショットの右上.
						|| (ex <= sx && sx <= ex + ew && sy <= ey && ey <= sy + sh)		// ショットの左下.
						|| (sx <= ex && ex <= sx + sw && sy <= ey && ey <= sy + sh))	// ショットの右下.
					{
						((CShot *)m_vecpShotList[j])->Set(2);	// 2にセット.
						pEnemyMap->m_vecEnemyMapDataList[i]->m_nLife--;	// ライフを減らす.
						if (pEnemyMap->m_vecEnemyMapDataList[i]->m_nLife <= 0){	// 0以下.
							m_pScene->m_pGameSystem->m_nScore += pEnemyMap->m_vecEnemyMapDataList[i]->m_nScore;	// スコアを加算.
							pEnemyMap->m_vecEnemyMapDataList[i]->m_nState = 3;	// 状態3.
						}
					}
				}
			}
			else if (iState == 2){	// 2なら.
				((CShot *)m_vecpShotList[j])->Set(0);	// 0にリセット.
			}
		}
		// 敵ショットと自機の当たり判定.
		int nn = pEnemyMap->m_vecEnemyMapDataList[i]->m_vecpShotList.size();
		for (int iii = 0; iii < nn; iii++){
			int esx = pEnemyMap->m_vecEnemyMapDataList[i]->m_vecpShotList[iii]->m_x - pMap->m_iScreenRX;	// 敵の画面座標ex.(こちらは右が正, なので正.)
			int esy = pMap->m_iScreenUY - pEnemyMap->m_vecEnemyMapDataList[i]->m_vecpShotList[iii]->m_y;	// 敵の画面座標ey.(こちらは上が正, なので逆.)
			int esw = pEnemyMap->m_vecEnemyMapDataList[i]->m_vecpShotList[iii]->m_iWidth;
			int esh = pEnemyMap->m_vecEnemyMapDataList[i]->m_vecpShotList[iii]->m_iHeight;
			int px = m_x;	// m_x.
			int py = m_y;	// m_y.
			int pw = m_iWidth;	// m_iWidth.
			int ph = m_iHeight;	// m_iHeight.
			if ((esx <= px && px <= esx + esw && esy <= py && py <= esy + esh)		// プレイヤーの左上.
				|| (px <= esx && esx <= px + pw && esy <= py && py <= esy + esh)		// プレイヤーの右上.
				|| (esx <= px && px <= esx + esw && py <= esy && esy <= py + ph)		// プレイヤーの左下.
				|| (px <= esx && esx <= px + pw && py <= esy && esy <= py + ph))	// プレイヤーの右下.
			{
				SetState(1);	// 1にする.
				// ゲームオーバー.
				//if (((CGameScene *)m_pScene)->m_pMessageArea->m_dwVisibleInterval == 0){	// まだセットされてないなら.
				//	if (m_pScene->m_pGameSystem->m_nRest == 0){	// 残機なし.
				//		((CGameScene *)m_pScene)->m_pMessageArea->SetVisibleTimer(5000);	// 5秒.
				//	}
				//}
				// リスタート.
				if (m_dwRestartInterval == 0){	// まだセットされていないなら.
					if (m_pScene->m_pGameSystem->m_nRest == 0){	// 残機なし.
						((CGameScene *)m_pScene)->m_pMessageArea->SetVisibleTimer(5000);	// 5秒.
						SetRestartTimer(10000);	// 10秒.
					}
					else{
						SetRestartTimer(5000);	// 5秒.
					}
				}
			}
		}
		// 敵と自機の当たり判定.
		if (pEnemyMap->m_vecEnemyMapDataList[i]->m_nState == 1){	// 表示.
			int ex = pEnemyMap->m_vecEnemyMapDataList[i]->m_x - pMap->m_iScreenRX;	// 敵の画面座標ex.(こちらは右が正, なので正.)
			int ey = pMap->m_iScreenUY - pEnemyMap->m_vecEnemyMapDataList[i]->m_y;	// 敵の画面座標ey.(こちらは上が正, なので逆.)
			int ew = pEnemies->m_vecEnemiesList[pEnemyMap->m_vecEnemyMapDataList[i]->m_nEnemyNo]->m_iWidth;	// 幅.
			int eh = pEnemies->m_vecEnemiesList[pEnemyMap->m_vecEnemyMapDataList[i]->m_nEnemyNo]->m_iHeight;	// 高さ.
			int px = m_x;	// m_x.
			int py = m_y;	// m_y.
			int pw = m_iWidth;	// m_iWidth.
			int ph = m_iHeight;	// m_iHeight.
			if ((ex <= px && px <= ex + ew && ey <= py && py <= ey + eh)		// プレイヤーの左上.
				|| (px <= ex && ex <= px + pw && ey <= py && py <= ey + eh)		// プレイヤーの右上.
				|| (ex <= px && px <= ex + ew && py <= ey && ey <= py + ph)		// プレイヤーの左下.
				|| (px <= ex && ex <= px + pw && py <= ey && ey <= py + ph))	// プレイヤーの右下.
			{
				SetState(1);	// 1にする.
				// ゲームオーバー.
				//if (((CGameScene *)m_pScene)->m_pMessageArea->m_dwVisibleInterval == 0){	// まだセットされてないなら.
				//	if (m_pScene->m_pGameSystem->m_nRest == 0){	// 残機なし.
				//		((CGameScene *)m_pScene)->m_pMessageArea->SetVisibleTimer(5000);	// 5秒.
				//	}
				//}
				// リスタート.
				if (m_dwRestartInterval == 0){	// まだセットされていないなら.
					if (m_pScene->m_pGameSystem->m_nRest == 0){	// 残機なし.
						((CGameScene *)m_pScene)->m_pMessageArea->SetVisibleTimer(5000);	// 5秒.
						SetRestartTimer(10000);	// 10秒.
					}
					else{
						SetRestartTimer(5000);	// 5秒.
					}
				}
			}
		}
		if (pEnemyMap->m_vecEnemyMapDataList[i]->m_nState <= 1){
			bClear = FALSE;
		}
	}
#else
	// ショットの描画.
	for (int i = 0, j = m_iShotIdx; i < m_vecpShotList.size(); i++){
		int iState = ((CShot *)m_vecpShotList[j])->Get();	// iState取得.
		if (iState == 0){	// 0なら.
			if (m_bShot){	// ショットが押された時.
				((CShot *)m_vecpShotList[j])->Set(1);	// 1をセット.
				m_iShotIdx = j + 1;
				if (m_iShotIdx >= m_vecpShotList.size()){	// サイズ以上.
					m_iShotIdx = 0;	// 0に戻す.
				}
				break;	// 抜ける.
			}
		}
		else if (iState == 1){	// 1なら.
			((CShot *)m_vecpShotList[j])->m_y--;	// y座標を1減らす.
			if (((CShot *)m_vecpShotList[j])->m_y <= -32){	// -32以下.
				((CShot *)m_vecpShotList[j])->Set(2);
			}
			else{	// ショットが有効な場合.
				CGameScene *pGameScene = (CGameScene *)m_pScene;	// pGameSceneにキャスト.
				CEnemyMap *pEnemyMap = pGameScene->m_pEnemyMap;	// pEnemyMapを取得.
				CEnemies *pEnemies = pEnemyMap->m_pEnemies;	// pEnemiesの取得.
				CMap *pMap = pGameScene->m_pMap;	// pMapを取得.
				int n = pEnemyMap->m_vecEnemyMapDataList.size();	// サイズを取得.
				for (int k = 0; k < n; k++){	// n繰り返す.
					if (pEnemyMap->m_vecEnemyMapDataList[k]->m_nState == 1){	// 表示.
						int ex = pEnemyMap->m_vecEnemyMapDataList[k]->m_x - pMap->m_iScreenRX;	// 敵の画面座標ex.(こちらは右が正, なので正.)
						int ey = pMap->m_iScreenUY - pEnemyMap->m_vecEnemyMapDataList[k]->m_y;	// 敵の画面座標ey.(こちらは上が正, なので逆.)
						int ew = pEnemies->m_vecEnemiesList[pEnemyMap->m_vecEnemyMapDataList[k]->m_nEnemyNo]->m_iWidth;	// 幅.
						int eh = pEnemies->m_vecEnemiesList[pEnemyMap->m_vecEnemyMapDataList[k]->m_nEnemyNo]->m_iHeight;	// 高さ.
						int sx = ((CShot *)m_vecpShotList[j])->m_x;	// ショットx.
						int sy = ((CShot *)m_vecpShotList[j])->m_y;	// ショットy.
						int sw = ((CShot *)m_vecpShotList[j])->m_iWidth;	// 幅.
						int sh = ((CShot *)m_vecpShotList[j])->m_iHeight;	// 高さ.
						if ((ex <= sx && sx <= ex + ew && ey <= sy && sy <= ey + eh)		// ショットの左上.
							|| (sx <= ex && ex <= sx + sw && ey <= sy && sy <= ey + eh)		// ショットの右上.
							|| (ex <= sx && sx <= ex + ew && sy <= ey && ey <= sy + sh)		// ショットの左下.
							|| (sx <= ex && ex <= sx + sw && sy <= ey && ey <= sy + sh))	// ショットの右下.
						{
							((CShot *)m_vecpShotList[j])->Set(2);	// 2にセット.
							pEnemyMap->m_vecEnemyMapDataList[k]->m_nLife--;	// ライフを減らす.
							if (pEnemyMap->m_vecEnemyMapDataList[k]->m_nLife <= 0){	// 0以下.
								pEnemyMap->m_vecEnemyMapDataList[k]->m_nState = 3;	// 状態3.
							}
						}
					}
				}
			}
		}
		else if (iState == 2){	// 2なら.
			((CShot *)m_vecpShotList[j])->Set(0);	// 0にリセット.
		}
		j++;	// jを増やす.
		if (j >= m_vecpShotList.size()){	// jがサイズ以上.
			j = 0;	// 0に戻す.
		}
	}
#endif
	if (bClear){
		if (m_dwRestartInterval == 0){	// まだセットされていないなら.
			m_bClear = TRUE;
			((CGameScene *)m_pScene)->m_pMessageArea->SetVisibleTimer(5000);	// 5秒.
			SetRestartTimer(10000);	// 10秒.
			m_pScene->m_pGameSystem->m_nRest = 0;
			bClear = FALSE;
		}
	}

	// タイマー経過でゲームオーバー表示.
	if (((CGameScene *)m_pScene)->m_pMessageArea->m_dwVisibleInterval != 0){	// セットされている.
		if (((CGameScene *)m_pScene)->m_pMessageArea->IsVisibleElapsed()){	// タイマー経過.
			((CGameScene *)m_pScene)->m_pMessageArea->m_bVisible = TRUE;	// TRUEにする.
		}
	}

	// タイマー経過でリスタート.
	if (m_dwRestartInterval != 0){	// まだセットされているなら.
		if (IsRestartElapsed()){	// 経過時間になったら.
			return 1;	// 1を返す.
		}
	}

	// シーン継続なら0.
	return 0;	// 0を返す.

}

// 位置をセットするSet.
void CPlayer::Set(int x, int y){

	// メンバのセット.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.

}

// アニメーションをセットするSet.
void CPlayer::Set(int iNo){

	// アニメーションのセット.
	m_iNo = iNo;	// m_iNoにiNoをセット.

}

// 状態をセットするSetState.
void CPlayer::SetState(int iState){

	// 引数をメンバにセット.
	m_nState = iState;	// m_nStateにiStateをセット.

}

// 状態を取得するGetState.
int CPlayer::GetState(){

	// 状態を返す.
	return m_nState;	// m_nStateを返す.
	
}

// 描画をするDraw.
void CPlayer::Draw(){

	// 描画.
	int iState = GetState();	// 状態を取得.
	if (iState == 0){	// iStateが0なら.
		//CCharacter::Draw(m_x, m_y, m_iNo);	// CCharacter::Drawで描画.
		CCharacter::DrawSprite(m_x, m_y, m_iNo);	// CCharacter::DrawSpriteで描画.
	}
	else if (iState == 1){	// 1の場合.
		DrawExplosion();	// 爆発.
	}

}

// ショットを描画するDrawShot.
void CPlayer::DrawShot(){

	// ショットの描画.
	for (int i = 0; i < m_vecpShotList.size(); i++){
		int iState = ((CShot *)m_vecpShotList[i])->Get();	// iState取得.
		if (iState == 1){	// 状態が1なら描画.
			((CShot *)m_vecpShotList[i])->DrawSprite(((CShot *)m_vecpShotList[i])->m_x, ((CShot *)m_vecpShotList[i])->m_y, 0);	// 描画.
		}
		else if (iState == 0){	// 0なら自機の座標.
			((CShot *)m_vecpShotList[i])->Set(m_x + 32 / 2 - 4 / 2, m_y);
			//((CShot *)m_vecpShotList[i])->DrawSprite(((CShot *)m_vecpShotList[i])->m_x, ((CShot *)m_vecpShotList[i])->m_y, 0);	// 描画.
		}
	}

}

// エクスプロージョンを描画するDrawExplosion.
void CPlayer::DrawExplosion(){

	// エクスプロージョンの描画.
	if (m_pExplosion != NULL){	// m_pExplosionがNULLでない.
		((CExplosion *)m_pExplosion)->DrawAnimation(m_x, m_y);	// アニメーション描画.
	}

}

// ショットの作成CreateShot.
void CPlayer::CreateShot(int iSize){

	// ショットの作成.
	for (int i = 0; i < iSize; i++){	// iSize個繰り返す.
		CShot *pShot = new CShot(m_pScene);	// CShotオブジェクトの作成.
		pShot->Add(0, 32, 4, 32, IDB_SHARED2);	// イメージ追加.
		pShot->AddMask(320 + 0, 32, 4, 32, IDB_SHARED2);	// マスク.追加.
		pShot->Set(m_x + 32 / 2 - 4 / 2, m_y);	// pShot->Setでm_x, m_yをセット.
		pShot->Set(0);	// 状態0をセット.
		m_vecpShotList.push_back(pShot);	// m_vecpShotList.push_backで追加.
	}

}

// エクスプロージョンの作成CreateExplosion.
void CPlayer::CreateExplosion(){

	// CExplosionの作成.
	CExplosion *pExplosion = new CExplosion(m_pScene);	// pExplosionの生成.
	pExplosion->Add(0, 64, 32, 32, IDB_SHARED2);	// イメージ追加.
	pExplosion->AddMask(320 + 0, 64, 32, 32, IDB_SHARED2);	// マスク追加.
	pExplosion->Add(32, 64, 32, 32, IDB_SHARED2);	// イメージ追加.
	pExplosion->AddMask(320 + 32, 64, 32, 32, IDB_SHARED2);	// マスク追加.
	pExplosion->Add(64, 64, 32, 32, IDB_SHARED2);	// イメージ追加.
	pExplosion->AddMask(320 + 64, 64, 32, 32, IDB_SHARED2);	// マスク追加.
	pExplosion->Add(96, 64, 32, 32, IDB_SHARED2);	// イメージ追加.
	pExplosion->AddMask(320 + 96, 64, 32, 32, IDB_SHARED2);	// マスク追加.
	pExplosion->Set(m_x, m_y);	// 位置のセット.
	m_pExplosion = pExplosion;	// m_pExplosionにpExplosionをセット.

}

// リスタートタイマーのセットSetRestartTimer.
void CPlayer::SetRestartTimer(DWORD dwInterval){

	// リスタートインターバルのセット.
	m_dwRestartInterval = dwInterval;	// m_dwRestartIntervalにdwIntervalをセット.

	// タイマーのセット.
	const CScene *pScene = m_pScene;	// m_pSceneをpSceneに格納.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTimeをpTimeに格納.
	m_dwRestartTimerStart = pTime->GetSystemTime();	// pTime->GetSystemTimeで取得した時刻をm_dwRestartTimerStartに格納.

}

// リスタートタイマーが経過時間を過ぎたかをチェックIsRestartElapsed.
BOOL CPlayer::IsRestartElapsed(){

	// 現在時刻の取得.
	const CScene *pScene = m_pScene;	// m_pSceneをpSceneに格納.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTimeをpTimeに格納.
	DWORD dwNow = pTime->GetSystemTime();	// pTime->GetSystemTimeで取得した時刻をdwNowに格納.

	// 経過時間チェック.
	if (dwNow - m_dwRestartTimerStart >= m_dwRestartInterval){	// m_dwRestartInterval以上なら.
		m_dwRestartTimerStart = dwNow;	// dwNowをm_dwRestartTimerStartにセット.
		return TRUE;	// TRUEを返す.
	}
	else{
		return FALSE;	// FALSEを返す.
	}

}